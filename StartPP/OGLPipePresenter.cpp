//---------------------------------------------------------------------------
#include "stdafx.h"
#include <math.h>
#include "OGLPipePresenter.h"
#include "Colors.h"
#include "Rotate.h"
#include "GlRenderer.h"
#include "MainFrm.h"
#include "gl/GLU.h"
#include "resource.h"

extern float Round(float x, int N);

//---------------------------------------------------------------------------
//#pragma package(smart_init)

#define OGL_INIT_ONCE

inline float DegToRad(float x)
{
	return x * atan(1.0f) / 45;
}

inline float RadToDeg(float x)
{
	return x * 45 / atan(1.0f);
}

inline float sgn(float x)
{
	return (x > 0) ? 1.0f : -1.0f;
}

void COGLPipePresenter::calc_angles(float x, float y, float z)
{
}

void errorCallback(GLenum errorCode)
{
	AfxMessageBox(CString(gluErrorString(errorCode)));
}

static GLuint texture1;

void COGLPipePresenter::SetupLighting()
{
	GLfloat MaterialAmbient[] = {
		0.1f, 0.1f, 0.1f, 1.0f
	};
	GLfloat MaterialDiffuse[] = {
		0.1f, 1.0f, 1.0f, 1.0f
	};
	GLfloat MaterialSpecular[] = {
		0.8f, 0.8f, 0.8f, 1.0f
	};
	GLfloat MaterialShininess[] = {
		30.0f
	};
	GLfloat AmbientLightPosition[] = {
		0.2f, .2f, 1.0f, 0.0f
	};
	GLfloat LightAmbient[] = {
		0.2f, 0.2f, 0.2f, 1.0f
	};
	glMaterialfv(GL_FRONT, GL_AMBIENT, MaterialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MaterialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MaterialShininess);
	glLightfv(GL_LIGHT0, GL_POSITION, AmbientLightPosition);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LightAmbient);
	//    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glShadeModel(GL_SMOOTH);
	if (m_ViewSettings.ShowNapr)
	{
#define TEX_WIDTH 256
		//Graphics::TBitmap *bitmap = new Graphics::TBitmap; 
		//bitmap->LoadFromFile(MainForm1->Table2->DatabaseName + "\\Napr.bmp" );
		//GLubyte TexImage[4 *TEX_WIDTH]; 
		//for(int i = 0; i < TEX_WIDTH; i++ ) {
		//   TexImage[4 *i] = (GLbyte)GetRValue(bitmap->Canvas->Pixels[i][0]);
		//   TexImage[4 *i + 1] = (GLbyte)GetGValue(bitmap->Canvas->Pixels[i][0]);
		//   TexImage[4 *i + 2] = (GLbyte)GetBValue(bitmap->Canvas->Pixels[i][0]);
		//   TexImage[4 *i + 3] = (GLbyte)255; 
		//};
		//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		//glGenTextures(1, &texture1);
		//glBindTexture(GL_TEXTURE_1D, texture1);
		//glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		//glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		//glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		//glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, TEX_WIDTH, 0, GL_RGBA, GL_UNSIGNED_BYTE, 
		//TexImage);
		//delete bitmap; 
		//glEnable(GL_TEXTURE_1D);
		//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	}
}

void box(float dx, float dy, float dz)
{
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(- dx / 2, - dy / 2, dz / 2);
	glVertex3f(dx / 2, - dy / 2, dz / 2);
	glVertex3f(dx / 2, dy / 2, dz / 2);
	glVertex3f(- dx / 2, dy / 2, dz / 2);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(- dx / 2, - dy / 2, - dz / 2);
	glVertex3f(dx / 2, - dy / 2, - dz / 2);
	glVertex3f(dx / 2, dy / 2, - dz / 2);
	glVertex3f(- dx / 2, dy / 2, - dz / 2);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(- dx / 2, - dy / 2, - dz / 2);
	glVertex3f(- dx / 2, dy / 2, - dz / 2);
	glVertex3f(- dx / 2, dy / 2, dz / 2);
	glVertex3f(- dx / 2, - dy / 2, dz / 2);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(dx / 2, - dy / 2, - dz / 2);
	glVertex3f(dx / 2, dy / 2, - dz / 2);
	glVertex3f(dx / 2, dy / 2, dz / 2);
	glVertex3f(dx / 2, - dy / 2, dz / 2);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(- dx / 2, - dy / 2, - dz / 2);
	glVertex3f(dx / 2, - dy / 2, - dz / 2);
	glVertex3f(dx / 2, - dy / 2, dz / 2);
	glVertex3f(- dx / 2, - dy / 2, dz / 2);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(- dx / 2, dy / 2, - dz / 2);
	glVertex3f(dx / 2, dy / 2, - dz / 2);
	glVertex3f(dx / 2, dy / 2, dz / 2);
	glVertex3f(- dx / 2, dy / 2, dz / 2);
	glEnd();
}

float sin_arr[13], cos_arr[13];

void glVertex3(float x, float y, float z)
{
	glVertex3f(x, y, z);
}

void glRot(float x)
{
	glRotatef(x, 1, 0, 0);
}

void SetColor(TColor c, bool Selected);

const float M_PI = 3.1415926f;

void COGLPipePresenter::draw_styk(float l_gen, float rad, float str_x_rot, float
                                  str_tg_2, float end_tg_2, float t1, float t2, bool DrawEnd)
{
	if (m_ViewSettings.ShowNapr)
		glColor3f(1, 1, 1);
	for (int i = 0; i < 12; i++)
	{
		sin_arr[i] = sin(2 * M_PI * i / 12);
		cos_arr[i] = cos(2 * M_PI * i / 12);
	}
	sin_arr[12] = sin_arr[0];
	cos_arr[12] = cos_arr[0];
	CRotator Rot(0, 0, str_x_rot);
	for (int i = 0; i < 12; i++)
	{
		float ang = 2 * M_PI * i / 12, ang1 = 2 * M_PI * (i + 1) / 12;
		glBegin(GL_QUADS); //      LINE_LOOP);
		glNormal3f(0, sin_arr[i], cos_arr[i]);
		float x = rad * sin(ang + str_x_rot) * str_tg_2, y = rad * sin(ang + str_x_rot), z =
			rad * cos(ang + str_x_rot);
		Rot.x_rotate(x, y, z);
		glTexCoord1f(1 - t1);
		glVertex3f(x, y, z);
		glTexCoord1f(1 - t2);
		glVertex3f(l_gen + rad * sin_arr[i] * end_tg_2, rad * sin_arr[i], rad * cos_arr[i]);
		glNormal3f(0, sin_arr[i + 1], cos_arr[i + 1]);
		glVertex3f(l_gen + rad * sin_arr[i + 1] * end_tg_2, rad * sin_arr[i + 1], rad * cos_arr[i + 1]);
		x = rad * sin(ang1 + str_x_rot) * str_tg_2 , y = rad * sin(ang1 + str_x_rot) , z =
			rad * cos(ang1 + str_x_rot);
		Rot.x_rotate(x, y, z);
		glTexCoord1f(1 - t1);
		glVertex3f(x, y, z);
		glEnd();
	}
	if (!DrawEnd) return;
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 12; i++)
	{
		float ang = 2 * M_PI * i / 12;
		//float ang1 = 2 *M_PI *(i + 1) / 12;
		glNormal3f(0, sin_arr[i], cos_arr[i]);
		float x = rad * sin(ang + str_x_rot) * str_tg_2, y = rad * sin(ang + str_x_rot), z =
			rad * cos(ang + str_x_rot);
		Rot.x_rotate(x, y, z);
		glTexCoord1f(1 - t2);
		glVertex3f(l_gen + rad * sin_arr[i] * end_tg_2, rad * sin_arr[i], rad * cos_arr[i]);
		glNormal3f(0, sin_arr[i + 1], cos_arr[i + 1]);
		glVertex3f(l_gen + rad * sin_arr[i + 1] * end_tg_2, rad * sin_arr[i + 1], rad * cos_arr[i + 1]);
	}
	glEnd();
}

enum TPipeEnds
{
	PE_NONE,
	PE_OTVOD,
	PE_STYK,
	PE_ARMAT,
	PE_KO,
	PE_KU
};

void set_pipe_end1(TPipeEnds& pipe_end, TNodeElement el)
{
	switch (el)
	{
	case elOtvodS:
	case elOtvodI:
	case elOtvodF:
		pipe_end = PE_OTVOD;
		break;
	case elArmat:
		pipe_end = PE_ARMAT;
		break;
	case elCompOs:
		pipe_end = PE_KO;
		break;
	case elCompUg:
		pipe_end = PE_KU;
		break;
	default:
		pipe_end = PE_STYK;
	}
}

void set_pipe_end2(TPipeEnds& pipe_end, TNodeElement el)
{
	switch (el)
	{
	case elArmat:
		pipe_end = PE_ARMAT;
		break;
	case elCompOs:
		pipe_end = PE_KO;
		break;
	case elCompUg:
		pipe_end = PE_KU;
		break;
	default:
		pipe_end = PE_NONE;
	}
}

void Cone(float height, float Rad1, float Rad2)
{
	glPushMatrix();
	glColor3f(1, 0, 1);
	glRotatef(90, 0, 1, 0);
	GLUquadricObj* quadObj = gluNewQuadric();
	//       gluQuadricTexture(quadObj, GL_TRUE);
	gluQuadricDrawStyle(quadObj, GLU_FILL);
	gluQuadricNormals(quadObj, GLU_SMOOTH);
	gluCylinder(quadObj, Rad1, Rad2, height, 12, 2);
	gluDeleteQuadric(quadObj);
	glPopMatrix();
}

void Cylinder(float height, float Rad)
{
	Cone(height, Rad, Rad);
}

void Sphere(float Rad)
{
	GLUquadricObj* quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj, GLU_FILL);
	gluQuadricNormals(quadObj, GLU_SMOOTH);
	gluSphere(quadObj, Rad, 12, 12);
	gluDeleteQuadric(quadObj);
}

void SetColor(TColor c, bool Selected)
{
	c = Selected ? clYellow : c;
	{
		byte r = GetRValue(c);
		byte g = GetGValue(c);
		byte b = GetBValue(c);
		glColor3f(float(r) / 256, float(g) / 256, float(b) / 256);
		GLfloat MaterialSpecular[] = {
			0.8f, 0.8f, 0.8f, 1.0f
		};
		glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialSpecular);
	}
}

void SetPipeColor(Pipe& p, bool Selected)
{
	TColor c;
	if (p.P_type > Max_pipe_type)
		if (p.P_type == INVALID_LOOP)
		{
			c = INVALID_LOOP_COLOR;
		}
		else
			c = getPipeColor(0);
	else
		c = getPipeColor(p.P_type);
	SetColor(c, Selected);
}

const int KO_SECTIONS = 3;

void COGLPipePresenter::AddLine(float* p1, float* p2, int NAYZ, Pipe& p)
{
	{
		float px1 = p1[0], py1 = p1[1], pz1 = p1[2], px2 = p2[0], py2 = p2[1], pz2 = p2[2];
		rot.Rotate(px1, py1, pz1);
		rot.Rotate(px2, py2, pz2);
		int x1 = ToScrX(px1), y1 = ToScrY(py1);
		int x2 = ToScrX(px2), y2 = ToScrY(py2);
		Interval_ pi;
		pi.StrP = NAYZ;
		pi.EndP = p.EndP;
		pi.x1 = x1;
		pi.y1 = y1;
		pi.x2 = x2;
		pi.y2 = y2;
		pi.Diam = p.Diam / 2000 * m_ViewSettings.ScrScale;
		PipeArr->Intervals.push_back(pi);
	}

	glPushMatrix();
	bool Selected = pvecSel->Contains(NAYZ, p.EndP);
	bool NodeSelected = pvecSel->Contains(p.EndP, p.EndP);
	bool NodeSelectedF = pvecSel->Contains(NAYZ, NAYZ);

	SetPipeColor(p, Selected);
	float x = p.dx, y = p.dy, z = p.dz, a_plan, a_prof, l_plan, l_gen;
	l_gen = sqrt(x * x + y * y + z * z);
	l_plan = sqrt(x * x + y * y);
	if (fabs(x) + fabs(y) < 0.001)
	{
		a_plan = 0;
		a_prof = (z > 0) ? 90.0f : -90.0f;
	}
	else
	{
		a_prof = RadToDeg(atan(z / l_plan));
		if (fabs(x) < 0.001)
			a_plan = (y > 0) ? 90.0f : -90.0f;
		else
		{
			a_plan = RadToDeg(atan(y / x));
			if (x < 0)
				a_plan = (y < 0) ? -180 + a_plan : 180 + a_plan;
		}
	}
	glTranslatef(p1[0], p1[1], p1[2]);
	glRotatef(a_plan, 0, 0, 1);
	glRotatef(- a_prof, 0, 1, 0);
	glPushMatrix();
	// ��� X - ����� �����
	Pipe pn, // ��������� �������
	     pp; // ���������� �������
	float pn_len;
	float pp_len;
	float pn_cos = 1;
	float pp_cos = 1;
	float str_x_rot = 0;
	float str_tg_2;
	float end_tg_2;
	// ������� ����������� ���� ����� ��������� � ������� ��������
	CPipeArrayContext cnt;

	//      Ret_pipe r=PipeArr->Ret[NAYZ][0];
	TPipeEnds pe_start = PE_NONE, pe_end = PE_NONE;
	if (PipeArr->HasOut(p.EndP))
	{
		pn = PipeArr->OutFirst(p.EndP, cnt);
		pn_len = sqrt(pn.dx * pn.dx + pn.dy * pn.dy + pn.dz * pn.dz);
		if (!(PipeArr->HasOutNext(cnt)) && // ������ 1 ��������� �������
			fabs(pn_len) > 0.00001)
			if (fabs(fabs(pn_cos = ((p.dx * pn.dx + p.dy * pn.dy + p.dz * pn.dz) / (l_gen * pn_len))
			) - 1) > 0.0001)
				set_pipe_end1(pe_end, p.MNEA);
			else
				set_pipe_end2(pe_end, p.MNEA);
	}
	if (PipeArr->HasIn(p.StrP))
	{
		pp = PipeArr->InFirst(p.StrP, cnt);
		pp_len = sqrt(pp.dx * pp.dx + pp.dy * pp.dy + pp.dz * pp.dz);
		Pipe p_tmp;
		if (!(PipeArr->HasInNext(cnt)))
		{ // ������ 1 �������� �������
			PipeArr->OutFirst(p.StrP, cnt);
			if (!PipeArr->HasOutNext(cnt) && fabs(pp_len) > 0.00001)
			{
				if (fabs(fabs(pp_cos = ((p.dx * pp.dx + p.dy * pp.dy + p.dz * pp.dz) / (l_gen *
					pp_len))) - 1) > 0.0001)
					set_pipe_end1(pe_start, pp.MNEA);
				else
					set_pipe_end2(pe_start, pp.MNEA);
			}
			if (pp.StrP == 0)
			{
				p_tmp = pp;
				p_tmp.Diam = p.Diam;
				AddOpor(p_tmp);
				if (NodeSelectedF)
				{
					SetColor(0, true);
					Sphere(p.Diam * 1.5f / 2000);
				}
			}
		}
	}
	CRotator Rot(DegToRad(- a_plan), 0, 0);
	Rot.z_rotate(pn.dx, pn.dy, pn.dz);
	if (pe_start != PE_NONE)
		Rot.z_rotate(pp.dx, pp.dy, pp.dz);
	Rot.SetRot(0, DegToRad(a_prof), 0);
	Rot.y_rotate(pn.dx, pn.dy, pn.dz);
	if (pe_start != PE_NONE)
		Rot.y_rotate(pp.dx, pp.dy, pp.dz);
	if (pe_end != PE_NONE)
	{
		float ang = (fabs(pn.dy) < 0.0001) ? 2 * atan(1.0f) * sgn(pn.dz) : atan(pn.dz / pn.dy);
		glRotatef(RadToDeg(ang), 1, 0, 0);
		Rot.SetRot(0, 0, - ang);
		Rot.x_rotate(pn.dx, pn.dy, pn.dz); // ������� � �.�., ������� �
		// ��������� 2-� ����
		// ��� X || 1-� �����
		if (pe_start != PE_NONE)
			Rot.x_rotate(pp.dx, pp.dy, pp.dz);
		float x1 = (1 - pn_cos) / (1 + pn_cos);
		if (x1 < 0)
			x1 = 0;
		end_tg_2 = sqrt(x1) * sgn(- pn.dy);
	}
	else
	{
		end_tg_2 = 0;
	}
	if (pe_start != PE_NONE)
	{
		str_x_rot = (fabs(pp.dy) < 0.0001f) ? 2 * atan(1.0f) * sgn(pp.dz) : atan(pp.dz / pp.dy);
		Rot.SetRot(0, 0, - str_x_rot);
		Rot.x_rotate(pp.dx, pp.dy, pp.dz); // ������� � �.�., ������� �
		float x1 = (1 - pp_cos) / (1 + pp_cos);
		if (x1 < 0)
			x1 = 0;
		str_tg_2 = sqrt(x1) * sgn(- pp.dy);
	}
	else
	{
		str_tg_2 = 0;
	}
	float styk_len = l_gen;
	switch (pe_start)
	{
	case PE_OTVOD:
		glTranslatef(pp.R_Otv * fabs(str_tg_2), 0, 0);
		styk_len -= pp.R_Otv * fabs(str_tg_2);
		str_tg_2 = 0;
		break;
	case PE_ARMAT:
		Cone(pp.R_Otv / 2, pp.Diam / 2000 / 4, pp.Diam / 2000);
		glTranslatef(pp.R_Otv / 2, 0, 0);
		styk_len -= pp.R_Otv / 2;
		str_tg_2 = 0;
		break;
	case PE_KO:
		break;
	case PE_KU:
		Cylinder(pp.R_Otv / 2, pp.Diam / 2000);
		glTranslatef(pp.R_Otv / 2, 0, 0);
		styk_len -= pp.R_Otv / 2;
		str_tg_2 = 0;
	case PE_NONE: break;
	case PE_STYK: break;
	default: break;
	}
	switch (pe_end)
	{
	case PE_OTVOD:
		styk_len -= p.R_Otv * fabs(end_tg_2);
		end_tg_2 = 0;
		break;
	case PE_ARMAT:
	case PE_KO:
	case PE_KU:
		styk_len -= p.R_Otv / 2;
		end_tg_2 = 0;
	case PE_NONE: break;
	case PE_STYK: break;
	default: break;
	}
	SetPipeColor(p, Selected);
	float t1 = 0, t2 = 0;
	if (fabs(p.NaprDop) >= 0.1)
	{
		t1 = p.NaprStr / p.NaprDop * (256.0f - 44.0f) / 256.0f;
		t2 = p.NaprEnd / p.NaprDop * (256.0f - 44.0f) / 256.0f;
	}
	draw_styk(styk_len, p.Diam / 2000, str_x_rot, str_tg_2, end_tg_2, t1, t2, true);
	glTranslatef(styk_len, 0, 0);
	switch (pe_end)
	{
	case PE_OTVOD:
		{
			float betta = acos(pn_cos) * sgn(pn.dy);
			const int N = 4;
			styk_len = 2 * p.R_Otv * fabs(sin(betta / (2 * N)));
			float styk_tan = tan(betta / (2 * N));
			glRotatef(RadToDeg(betta / N / 2), 0, 0, 1);
			for (int i = 0; i < N; i++)
			{
				SetColor(clRed, NodeSelected);
				draw_styk(styk_len, p.Diam / 2000, 0, styk_tan, -styk_tan, 0, 0, i == N - 1 ? true : false);
				glTranslatef(styk_len, 0, 0);
				glRotatef(RadToDeg(betta / N), 0, 0, 1);
			}
		}
		break;
	case PE_ARMAT:
		Cone(p.R_Otv / 2, p.Diam / 2000, p.Diam / 2000 / 4);
		break;
	case PE_KO:
		// ������ �����������
		for (int i = 0; i < KO_SECTIONS; i++)
		{
			Cone(p.R_Otv / 2 / KO_SECTIONS, p.Diam / 2000, p.Diam * 1.5f / 2000.0f);
			glTranslatef(p.R_Otv / 2 / KO_SECTIONS, 0, 0);
			Cone(p.R_Otv / 2 / KO_SECTIONS, p.Diam * 1.5f / 2000, p.Diam / 2000.0f);
			glTranslatef(p.R_Otv / 2 / KO_SECTIONS, 0, 0);
		}
		break;
	case PE_KU:
		// ������� �����������
		Cylinder(p.R_Otv / 2, p.Diam / 2000);
		glTranslatef(p.R_Otv / 2, 0, 0);
		glColor3f(1, 0, 1);
		Sphere(p.Diam * 1.5f / 2000);
	case PE_NONE: break;
	case PE_STYK: break;
	default: break;
	}
	glPopMatrix();
	glTranslatef(l_gen, 0, 0);
	AddOpor(p);
	if (NodeSelected)
	{
		SetColor(0, true);
		Sphere(p.Diam * 1.5f / 2000);
	}
	glPopMatrix();
}

void COGLPipePresenter::AddOpor(Pipe& p)
{
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glDisable(GL_TEXTURE_1D);
	GLfloat MaterialSpecular[] = {
		0, 0, 0, 1.0
	};
	glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialSpecular);
	glRotatef(90, 0, 1, 0);
	float Diam = p.Diam / 1000;
	switch (p.MNEO)
	{
	case elMertOp:
		box(Diam * 1.5f, Diam * 1.5f, Diam * 0.5f);
		break;
	case elSkOp:
		glTranslatef(Diam / 2 + Diam / 4, 0, 0);
		box(Diam / 2, Diam * 1.5f, Diam * 1.5f);
		break;
	case elNaprOp:
		glTranslatef(Diam / 2 * 1.5f / 2, 0, 0);
		box(Diam * 1.5f / 2, Diam * 1.5f, Diam * 1.5f);
		break;
	case elNone: break;
	case elCompOs: break;
	case elCompUg: break;
	case elArmat: break;
	case elOtvodS: break;
	case elOtvodI: break;
	case elOtvodF: break;
	case elDiamChange: break;
	case elRast: break;
	case elSg: break;
	case elGestPd: break;
	case elUprOp: break;
	case elSelect: break;
	case elTroinic: break;
	default: break;
	}
	if (m_ViewSettings.ShowNapr)
		glEnable(GL_TEXTURE_1D);
	glPopMatrix();
}

void COGLPipePresenter::AddNodeElement(float* p, TNodeElement el, float ang)
{
};

void COGLPipePresenter::AddLineFrom(float* p1, float* p2, float Dist, float ang)
{
};

void COGLPipePresenter::AddPodushFrom(float* p1, float* p2, float Dist, float ang)
{
};

void COGLPipePresenter::AddCircle(float* p, float rad)
{
}

void COGLPipePresenter::PushMatrixes(void)
{
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, double(m_ClientRect.Width()), double(m_ClientRect.Height()), 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glDisable(GL_LIGHTING);
}

void COGLPipePresenter::PopMatrixes(void)
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glDisable(GL_LIGHTING);
}


void COGLPipePresenter::AddNodeNum(float* p, float Dist, float ang, int NodeNum, float rad)
{
	if (Points[NodeNum].set)
		return;

	glColor3f(0, 0, 0);
	CString str;
	str.Format(_T("%d"), NodeNum);
	rad /= 2.0f;
	//AddTextFrom(p,Dist,ang,int(rad*20/25),str,0,0);
	TEXTMETRIC tm;
	CSize sz = m_pRenderer->GetFontExtent(SVF_VALUES, str, &tm);
	float pw = CurPipe.Diam / 1000 * m_ViewSettings.ScrScale;
	Dist += (pw / 2);
	float _x = p[0], _y = p[1], _z = p[2];
	rot.Rotate(_x, _y, _z);
	int x = int(ToScrX(_x) - Dist * ElemScale * sin(ang));
	int y = int(ToScrY(_y) - Dist * ElemScale * cos(ang));
	int tw = sz.cx, th = sz.cy;

	PushMatrixes();
	glColor3f(0, 0, 0);
	glRasterPos3d(x - tw / 2, y + th / 4, 1);
	glPushAttrib(GL_LIST_BIT); // Pushes The Display List Bits
	glListBase(m_pRenderer->m_fontBases[SVF_VALUES]); // Sets The Base Character to 0
	glCallLists(str.GetLength(), GL_UNSIGNED_SHORT, str); // Draws The Display List Text
	glPopAttrib(); // Pops The Display List Bits
	glColor3ub(255, 0, 0);
	glBegin(GL_LINE_LOOP);
	int nSegments = 16;
	double M_2PI = 8 * atan(1.0);
	for (int i = 0; i < nSegments; i++)
	{
		glVertex3d(x + rad * sin(i * M_2PI / nSegments), y + rad * cos(i * M_2PI / nSegments), 1);
	}
	glEnd();

	glBegin(GL_LINES);
	int x1 = int(x + rad * ElemScale * sin(ang)), y1 = int(y + rad * ElemScale * cos(ang));
	glVertex3f(float(x1), float(y1), 1);
	glVertex3f(x1 + 2 * nTickSize * ElemScale * sin(ang), y1 + 2 * nTickSize * ElemScale * cos(ang), 1);
	glEnd();

	glColor3ub(255, 255, 255);
	GLfloat MaterialSpecular[] = {
		0.8f, 0.8f, 0.8f, 1.0f
	};
	glMaterialfv(GL_FRONT, GL_SPECULAR, MaterialSpecular);

	glPolygonOffset(0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < nSegments; i++)
	{
		glVertex3d(x + rad * sin(i * M_2PI / nSegments), y + rad * cos(i * M_2PI / nSegments), 1);
	}
	glEnd();
	glPolygonOffset(0, 0);

	PopMatrixes();
	glEnable(GL_LIGHTING);
};

extern float CalcAng(float, float);
extern float RadToDeg(float x);
extern float NormAng(float ang);

void COGLPipePresenter::AddTextFrom(float* p, float Dist, float ang, int size, CString txt, float Rotation, int TextMode)
{
	glDisable(GL_LIGHTING);
	size *= 15;
	size /= 12;

	TEXTMETRIC tm;
	CSize sz = m_pRenderer->GetFontExtent(SVF_AXES, txt, &tm);
	//sz.cx=tm.tmAveCharWidth*txt.GetLength();
	float pw = CurPipe.Diam / 1000 * m_ViewSettings.ScrScale / 2;
	if (Dist < 0)
		Dist -= (pw);
	else
		Dist += pw;
	float dx = CurPipe.dx, dy = CurPipe.dy, dz = CurPipe.dz;
	rot.Rotate(dx, dy, dz);
	//ang = CalcAng(dx, dy);
	//ang = -NormAng(ang);
	float px = p[0], py = p[1], pz = p[2];
	//Dist+= CurPipe.Diam/1000;///2;//*m_ViewSettings.ScrScale;
	rot.Rotate(px, py, pz);

	int x = int(ToScrX(px) - Dist * sin(ang));
	int y = int(ToScrY(py) - Dist * cos(ang));
	//Rotation =ang;//+atan(1.0f)*2;
	float tw = sz.cx * size / -m_pRenderer->m_fontSizes[SVF_AXES], th = (sz.cy * size / -m_pRenderer->m_fontSizes[SVF_AXES]);
	float tx = (tw * cos(Rotation) - th * sin(Rotation)),
		ty = (tw * sin(Rotation) + th * cos(Rotation));
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, double(m_ClientRect.Width()), 0, double(m_ClientRect.Height()), -1, 1);
	glMatrixMode(GL_MODELVIEW);

	glColor3b(0, 0, 0);
	float angG = RadToDeg(Rotation);
	glTranslatef(float(x) - float(tx) / 2, float(m_ClientRect.Height()) - y - float(ty) / 2, 1);//+ty),1);
	glRotatef(angG, 0, 0, 1);
	if (TextMode == tOVERLINE)
	{
		glBegin(GL_LINES);
		glVertex3f(0, (size + th * 3 / 4) / 2, 0);
		glVertex3f(tw, (size + th * 3 / 4) / 2, 0);
		glEnd();
	}
	//glBegin(GL_LINE_LOOP);
	//	glVertex3f(0,0,0);
	//	glVertex3f(0,th,0);
	//	glVertex3f(tw,th,0);
	//	glVertex3f(tw,0,0);
	//glEnd();
	glScalef(float(size), float(size), float(size));
	glPushAttrib(GL_LIST_BIT); // Pushes The Display List Bits
	glListBase(m_pRenderer->m_fontBases[SVF_AXES]); // Sets The Base Character to 0
	glCallLists(txt.GetLength(), GL_UNSIGNED_SHORT, LPCTSTR(txt)); // Draws The Display List Text
	glPopAttrib(); // Pops The Display List Bits
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
};

void COGLPipePresenter::Add2TextFrom(float* p, float Dist, float ang, int size,
                                     CString txt, CString txt1, float Rotation)
{
	AddTextFrom(p, Scl, ang, size, txt, Rotation, tNONE);
	AddTextFrom(p, Scl + size, ang, size, txt1, Rotation, tOVERLINE);
};

extern LPCTSTR LoadStr(UINT nID);

void COGLPipePresenter::AddVertLine(float* strPoint, float dz)
{
	float Dist = 40;
	CString txt1 = (dz > 0) ? LoadStr(IDS_PODJOM) : LoadStr(IDS_OPUSK),
		txt2;
	txt2.Format(_T("h=%.1f"), dz);
	TEXTMETRIC tm;
	CSize sz = m_pRenderer->GetFontExtent(SVF_VALUES, CString(txt1), &tm);
	CSize sz1 = m_pRenderer->GetFontExtent(SVF_VALUES, CString(txt2), &tm);
	int w = max(sz.cx,sz1.cx);
	int h = max(sz.cy,sz1.cy);
	//int w1 = w + w / 4;
	//    h+=h/5;
	int x = ToScrX(strPoint[0]), y = ToScrY(strPoint[1]);
	PushMatrixes();
	glDisable(GL_LIGHTING);
	glColor3b(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3i(x, y, 1);
	x += int(Dist * ElemScale / 2);
	y -= int(Dist * ElemScale);
	glVertex3i(x, y, 1);
	glVertex3i(x, y, 1);
	x += w;
	glVertex3i(x, y, 1);
	glEnd();
	x -= w;
	y -= h / 4;
	//float size = 15;
	glRasterPos3d(x, y, 1);
	glListBase(m_pRenderer->m_fontBases[SVF_RUS]); // Sets The Base Character to 0
	int ggg[222];
	for (int i = 0; i < txt1.GetLength(); i++)
	{
		ggg[i] = reinterpret_cast<unsigned char*>(txt1.GetBuffer())[i * 2];//+((unsigned char*)txt1.GetBuffer())[i*2+1]*256;
	}
	glPushAttrib(GL_LIST_BIT); // Pushes The Display List Bits
	glCallLists(txt1.GetLength(), GL_INT, ggg); // Draws The Display List Text
	y += h + h / 5;
	glListBase(m_pRenderer->m_fontBases[SVF_VALUES]); // Sets The Base Character to 0
	glRasterPos3d(x, y, 1);
	glCallLists(txt2.GetLength(), GL_UNSIGNED_SHORT, txt2); // Draws The Display List Text
	glPopAttrib();
	PopMatrixes();
	glEnable(GL_LIGHTING);
}

void COGLPipePresenter::Rotate(FLOAT_TYPE& x, FLOAT_TYPE& y, FLOAT_TYPE& z)
{
	rot.Rotate(x, y, z);
};

GLvoid COGLPipePresenter::initializeGL()
{
	glClearColor(1, 1, 1, 1);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	set_view();
	SetupLighting();
}

COGLPipePresenter::COGLPipePresenter(CPipeArray* PipeArray, CGLRenderer* rend, CRotator& _rot, CViewSettings& _viewSettings):
	CScreenPipePresenter(PipeArray, _rot, _viewSettings), ghRC(nullptr), ghDC(nullptr), m_pRenderer(rend)
{
	Scl = 15;
#if 0
   ghDC = GetDC(MainForm1->ViewPanel->Handle);
   if(!bSetupPixelFormat(ghDC) )
      return;
   ghRC = wglCreateContext(ghDC);
   if(ghRC == nullptr)
      ShowMessage( ":-)~ hrc == nullptr" );
   if(wglMakeCurrent(ghDC, ghRC) == false)
      ShowMessage( "Could not MakeCurrent" );
#endif
}

void COGLPipePresenter::set_view()
{
	float width = float(m_ClientRect.Width()), height = float(m_ClientRect.Height());
	glViewport(m_ClientRect.left, m_ClientRect.top, m_ClientRect.Width(), m_ClientRect.Height());
	//  aspect = (GLfloat) width / height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -(z_max + 2) * m_ViewSettings.ScrScale, -(z_min - 2) * m_ViewSettings.ScrScale);
	//            ;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

COGLPipePresenter::~COGLPipePresenter()
{
#if 0
   if(ghRC)
      wglDeleteContext(ghRC);
   if(ghDC)
      ReleaseDC(MainForm1->ViewPanel->Handle, ghDC);
#endif
}

void COGLPipePresenter::DrawCoordSys()
{
	glEnable(GL_LIGHTING);
	glClear(GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, m_ClientRect.Width(), 0, m_ClientRect.Height(), -100, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat light_position[] = {0,0,1,0};
	glLightfv(GL_LIGHT0,GL_POSITION, light_position);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_FALSE);
	glShadeModel(GL_SMOOTH);

	float xr = RadToDeg(rot.Fx_rot);
	float zr = RadToDeg(rot.Fz_rot);

	glTranslatef(50, 50, 0);
	glRotatef(xr, 1, 0, 0);
	glRotatef(zr, 0, 0, 1);
	glColor3f(0, 0, 1);
	DrawAxe('Z');
	glRotatef(90, 0, 1, 0);
	glColor3f(1, 0, 0);
	DrawAxe('X');
	glRotatef(-90, 1, 0, 0);
	glColor3f(0, 1, 0);
	DrawAxe('Y');
	glColor3f(0, 0, 0);
}


void COGLPipePresenter::DrawAxe(char Name)
{
	glPushMatrix();
	GLUquadricObj* quadObj = gluNewQuadric();

	gluQuadricDrawStyle(quadObj, GLU_FILL);
	gluQuadricNormals(quadObj, GLU_SMOOTH);
	gluCylinder(quadObj, 2, 2, 30, 10, 2);

	glTranslatef(0, 0, 30);

	gluDisk(quadObj, 5, 0, 10, 2);
	gluCylinder(quadObj, 5, 0, 15, 10, 2);
	//    gluDeleteQuadric(quadObj);

	glTranslatef(0, 0, 20);
	glDisable(GL_LIGHTING);
	HGDIOBJ oldfont = SelectObject(ghDC, GetStockObject(SYSTEM_FONT));

	// create the bitmap display lists
	// we're making images of glyphs 0 thru 255
	// the display list numbering starts at 1000, an arbitrary choice

	wglUseFontBitmaps(ghDC, Name, 1, 1000);
	SelectObject(ghDC, oldfont);
	glRasterPos2i(0, 0);
	glCallList(1000);
	glEnable(GL_LIGHTING);

	glPopMatrix();
}


//const float AxisSize=30;
void COGLPipePresenter::Draw(CRect ClientRect, /* TStatusBar *StatusBar1,*/bool Printing)
{
	wglMakeCurrent(ghDC, ghRC);
	//unsigned long s_start = timeGetTime();
	m_ClientRect = ClientRect;
	DrawMain(true);
	initializeGL();

	glTranslatef(m_ViewSettings.Xorg, - m_ViewSettings.Yorg + m_ClientRect.Height(), 0);
	glRotatef(RadToDeg(rot.Fx_rot), 1, 0, 0);
	glRotatef(RadToDeg(rot.Fz_rot), 0, 0, 1);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClearDepth(1.0);
	glEnable(GL_POLYGON_OFFSET_FILL);
	glPolygonOffset(1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_NORMALIZE);
	glScalef(m_ViewSettings.ScrScale, m_ViewSettings.ScrScale, m_ViewSettings.ScrScale);
	glBindTexture(GL_TEXTURE_1D, texture1);
	try
	{
		//#ifdef OGL_INIT_ONCE
#if 0
   if(m_bNewGeometry) {
      glNewList(1, GL_COMPILE_AND_EXECUTE);
      DrawMain(false);
      glEndList();
      m_bNewGeometry = false;
   }
   else
   glCallList(1);
#else
		DrawMain(false);
#endif
	}
	catch (...)
	{
	}
	DrawCoordSys();
	if (!Printing)
		SwapBuffers(ghDC);
	//StatusBar1->Panels->Items[1]->Text = IntToStr(timeGetTime() - s_start) + " ����";
	wglMakeCurrent(nullptr, nullptr);
	CString strText;
	strText.Format(LoadStr(IDS_FORMAT_UCH_UZL), NumPipes, NumNodes);
	static_cast<CMainFrame*>(AfxGetMainWnd())->m_wndStatusBar.SetPaneText(1, strText);

	//               "��������:"+IntToStr(NumPipes)+
	//              "  �����:"+IntToStr(NumNodes);
	//   DrawAxis(AxisSize,0,0,'X',Rot);
	//   DrawAxis(0,AxisSize,0,'Y',Rot);
	//   DrawAxis(0,0,AxisSize,'Z',Rot);
	//     wglMakeCurrent(nullptr,nullptr);
}

void COGLPipePresenter::DrawDottedRect(CDC* pDC, const CRect& rc, CRect clr)
{
	ghDC = pDC->m_hDC;
	Draw(clr, true);
	wglMakeCurrent(ghDC, ghRC);
	int x1 = rc.left, y1 = rc.top, x2 = rc.right, y2 = rc.bottom;
	int VP[4];
	glGetIntegerv(GL_VIEWPORT, VP);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(0, 0, 0);
	glDisable(GL_DEPTH_TEST);
	glOrtho(0.0, VP[2], VP[3], 0, -1, 1); // ��������� �������� ��
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0xCCCC);
	glBegin(GL_LINE_LOOP); // �������������� �������������
	glVertex3d(x1, y1, 0);
	glVertex3d(x1, y2, 0);
	glVertex3d(x2, y2, 0);
	glVertex3d(x2, y1, 0);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	SwapBuffers(ghDC);
}

RENDER render;

void InitializeGlobal(HWND hWndDlg)
{
	//	render.hDC = GetDC(MainForm1->ViewPanel->Handle);
	//	render.hMemDC = CreateCompatibleDC(render.hDC);
	//	render.bmRect=MainForm1->PaintBox1->ClientRect;
	render.hBm = CreateDIBSurface(hWndDlg);
	render.hBmOld = HBITMAP(SelectObject(render.hMemDC, render.hBm));
	if (!PrepareDIBSurface())
		AfxMessageBox(_T("The pixel format of the memory DC is not set properly"));
	render.hglRC = wglCreateContext(render.hMemDC);
	wglMakeCurrent(render.hMemDC, render.hglRC);
}


//***********************************************************************
// Function:	CleanUp
//


// Purpose:		Deletes the DIB section, memory DC, and rendering context
//
// Parameters:
//	  HWND 				hWndDlg
//
// Returns:
//	  void
//


//**********************************************************************
void CleanUp()
{
	if (render.hglRC)
	{
		wglMakeCurrent(nullptr, nullptr);
		wglDeleteContext(render.hglRC);
	}
	DeleteObject(render.hPal);
	render.hBm = HBITMAP(SelectObject(render.hMemDC, render.hBmOld));
	DeleteObject(render.hBm);
	DeleteDC(render.hMemDC);

	//	ReleaseDC(GetDlgItem(hWndDlg, IDC_PICTURE), render.hDC);
}

#define WIDTHBYTES(bits)  (((bits) + 31)/32 * 4)


//***********************************************************************
// Function:	CreateDIBSurface
//

// Purpose:		reates a DIB section as the drawing surface for gl calls
//
// Parameters:
//	  HWND 				hWndDlg
//
// Returns:
//	  HBITMAP
//


//**********************************************************************
HBITMAP CreateDIBSurface(HWND hWndDlg)
{
	BITMAPINFO* pbi = reinterpret_cast<BITMAPINFO *>(render.biInfo);
	ZeroMemory(pbi, sizeof(BITMAPINFO) );
	if (!render.hDC)
		return nullptr;
	pbi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	pbi->bmiHeader.biWidth = render.bmRect.right - render.bmRect.left;
	pbi->bmiHeader.biHeight = render.bmRect.bottom - render.bmRect.top;
	pbi->bmiHeader.biPlanes = 1;
	pbi->bmiHeader.biBitCount = WORD(GetDeviceCaps(render.hDC, PLANES) *
		GetDeviceCaps(render.hDC, BITSPIXEL));
	pbi->bmiHeader.biCompression = BI_RGB;
	pbi->bmiHeader.biSizeImage = WIDTHBYTES( DWORD(pbi->bmiHeader.biWidth) *pbi->
		bmiHeader.biBitCount) * pbi->bmiHeader.biHeight;
	return CreateDIBSection(render.hDC, pbi, DIB_RGB_COLORS, &render.lpBits, nullptr,
	                        DWORD(0));
}


//***********************************************************************
// Function:	PrepareDIBSurface
//
// Purpose:		Selects the DIB section into a memory DC and sets the pixel
//				format of the memory DC. A palette is created if the app is
//				running on a 8 bit device.
//
// Parameters:
//	  void
//
// Returns:
//	  BOOL
//


//**********************************************************************
BOOL PrepareDIBSurface(void)
{
	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR), // size of this pfd
		1, // version number
		PFD_DRAW_TO_WINDOW | PFD_DRAW_TO_BITMAP | PFD_SUPPORT_OPENGL | PFD_SUPPORT_GDI,
		PFD_TYPE_RGBA,
		// RGBA type
		24, // 24-bit color depth
		0, 0, 0, 0, 0, 0, // color bits ignored
		0, // no alpha buffer
		0, // shift bit ignored
		0, // no accumulation buffer
		0, 0, 0, 0, // accum bits ignored
		32, // 32-bit z-buffer
		0, // no stencil buffer
		0, // no auxiliary buffer
		PFD_MAIN_PLANE, // main layer
		0, // reserved
		0, 0, 0 // layer masks ignored
	};
	BOOL bRet = TRUE;
	int nIndex;
	pfd.cColorBits = byte(GetDeviceCaps(render.hDC, PLANES) * GetDeviceCaps(
		render.hDC, BITSPIXEL));
	nIndex = ChoosePixelFormat(render.hMemDC, &pfd);
	if (!nIndex)
		bRet = FALSE;
	DescribePixelFormat(render.hMemDC, nIndex, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
	if (!SetPixelFormat(render.hMemDC, nIndex, &pfd))
		bRet = FALSE;

	//   if (bRet && pfd.dwFlags & PFD_NEED_PALETTE)
	//     CreateRGBPalette();
	return bRet;
}

void COGLPipePresenter::InitGLScene()
{
	glClearColor(1, 1, 1, 1);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	//float width=MainForm1->PaintBox1->Width,
	//      height=MainForm1->PaintBox1->Height;
	//    GLfloat aspect;
	glViewport(0, 0, render.bmRect.right, render.bmRect.bottom);
	//  aspect = (GLfloat) width / height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, render.bmRect.right, 0, render.bmRect.bottom, -10000, 10000
	);
	//            (z_min-1)*m_ViewSettings.ScrScale,(z_max+1)*m_ViewSettings.ScrScale);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	SetupLighting();
}

void COGLPipePresenter::Print(CDC* pDC, CPrintInfo* pInfo, CRotator* Rot, HWND hWnd)
{
	render.hDC = pDC->m_hDC;//GetDC(hWnd);
	render.hMemDC = CreateCompatibleDC(render.hDC);
	render.bmRect.left = render.bmRect.top = 0;
	float fAspPrn = float(pInfo->m_rectDraw.Height()) / pInfo->m_rectDraw.Width();
	float fAspScr = float(m_ClientRect.Height()) / m_ClientRect.Width();
	CRect clr1(m_ClientRect);
	if (fAspPrn > fAspScr)
	{
		render.bmRect.right = m_ClientRect.Width();
		m_ClientRect.bottom = render.bmRect.bottom = int(m_ClientRect.Height() * fAspPrn / fAspScr);
	}
	else
	{
		m_ClientRect.right = render.bmRect.right = int(m_ClientRect.Width() / fAspPrn * fAspScr);
		render.bmRect.bottom = m_ClientRect.Height();
	}
	InitializeGlobal(hWnd);
	initializeGL();
	m_pRenderer->BuildAllFonts();
	if (fAspPrn > fAspScr)
		m_ViewSettings.Yorg += (render.bmRect.bottom - clr1.Height()) / 2;
	else
		m_ViewSettings.Xorg += (render.bmRect.right - clr1.Width()) / 2;

	glTranslatef(m_ViewSettings.Xorg, - m_ViewSettings.Yorg + m_ClientRect.Height(), 0);
	glRotatef(RadToDeg(rot.Fx_rot), 1, 0, 0);
	glRotatef(RadToDeg(rot.Fz_rot), 0, 0, 1);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glScalef(m_ViewSettings.ScrScale, m_ViewSettings.ScrScale, m_ViewSettings.ScrScale);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	SetupLighting();
	DrawMain(false);
	//render.hPalOld = SelectPalette(pDC->m_hDC, render.hPal, FALSE);
	//if(float (pInfo->m_rectDraw.Height()) / pInfo->m_rectDraw.Width() > float (render.bmRect.
	//bottom) / render.bmRect.right)
	{
		//float scl = float(pInfo->m_rectDraw.Width()) / render.bmRect.right;
		StretchDIBits(pDC->m_hDC, pInfo->m_rectDraw.left, pInfo->m_rectDraw.top
		              , pInfo->m_rectDraw.Width(), pInfo->m_rectDraw.Height(), 0, 0, render.bmRect.right,
		              render.bmRect.bottom, render.lpBits, reinterpret_cast<BITMAPINFO *>(render.biInfo),
		              DIB_RGB_COLORS, SRCCOPY);
		//		StretchDIBits(pDC->m_hDC, pInfo->m_rectDraw.left, pInfo->m_rectDraw.top+ int(pInfo->m_rectDraw.Height() / 2 - render.bmRect.bottom *scl / 2)
		//		, pInfo->m_rectDraw.Width(), int(render.bmRect.bottom *scl), 0, 0, render.bmRect.right, 
		//		render.bmRect.bottom, render.lpBits, (BITMAPINFO *)render.biInfo, 
		//		DIB_RGB_COLORS, SRCCOPY);
	}
	//else
	//{
	//	float scl = float (pInfo->m_rectDraw.Height()) / render.bmRect.bottom; 
	//	StretchDIBits(pDC->m_hDC, pInfo->m_rectDraw.left+int( pInfo->m_rectDraw.Width() / 2 - render.bmRect.right *scl / 2), pInfo->m_rectDraw.top, 
	//	int(render.bmRect.right *scl), pInfo->m_rectDraw.Height(), 0, 0, render.bmRect.right, render.
	//	bmRect.bottom, render.lpBits, (BITMAPINFO *)render.biInfo, DIB_RGB_COLORS, 
	//	SRCCOPY);
	//}
	//SelectPalette(render.hDC, render.hPalOld, FALSE);
	CleanUp();
}

void COGLPipePresenter::PrepareBmp(CDC* pDC, HWND hWnd, CRect ClientRect)
{
	render.hDC = pDC->m_hDC;//GetDC(hWnd);
	render.hMemDC = CreateCompatibleDC(render.hDC);
	render.bmRect = ClientRect;
	InitializeGlobal(hWnd);
	initializeGL();
	ghDC = render.hMemDC;
	ghRC = render.hglRC;
	m_pRenderer->BuildAllFonts();
}
