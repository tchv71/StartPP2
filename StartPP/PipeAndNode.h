#pragma once

class CArchive;
class CStartPPDoc;
class CPipeAndNode;

class CAngles
{
public:
	float a_plan, a_prof, a_plan_rel, a_plan_prev, l_plan, l_gen, uklon;
	void GetRelAngle(CStartPPDoc* m_pDoc, CPipeAndNode* pPnN);
	void calc_angles(float x, float y, float z);

};


class CPipeAndNode : public CAngles
{
public:
	CPipeAndNode(void);
	~CPipeAndNode(void);
	float m_NAYZ;
	float m_KOYZ;
	float m_OSIX;
	float m_OSIY;
	float m_OSIZ;
	CStringA m_NAMA;
	float m_DIAM;
	float m_NTOS;
	float m_RTOS;
	float m_RATE;
	float m_RADA;
	float m_VETR;
	float m_VEIZ;
	float m_VEPR;
	float m_KOPE;
	float m_KOPR;
	float m_KOYS;
	float m_KORA;
	CStringA m_MNEA;
	CStringA m_MNEO;
	float m_DABI;
	float m_RAOT;
	float m_DIGI;
	CStringA m_MARI;
	float m_NOTO;
	float m_RATO;
	float m_KOTR;
	float m_VESA;
	float m_SEOP;
	float m_VEYS;
	CStringA m_PELI;
	CStringA m_PEYG;
	CStringA m_TIDE;
	float m_RASG;
	float m_DEFX;
	float m_DEFY;
	float m_DEFZ;
	float m_DEME;
	float m_NAGV;
	float m_NAGX;
	float m_NAGY;
	float m_NAGZ;
	float m_VESX;
	float m_VESY;
	float m_VESZ;
	float m_SILX;
	float m_SILY;
	float m_SILZ;
	float m_MOMX;
	float m_MOMY;
	float m_MOMZ;
	float m_NAAN;
	float m_NABA;
	float m_VIZA;
	float m_SHTR;
	float m_VIVO;
	float m_INDX;
	float m_NONE;
	CStringA m_VREZKA;
	CStringA m_TEXT;
	float m_KOR;
	float m_VIZA2;
	float m_OS_TR1;
	float m_OS_TR2;
	float m_KORPUS;
	BOOL m_TYPE_KOMP;
	float m_L_KOMP;
	bool operator ==(const CPipeAndNode& other) const;
	bool operator !=(const CPipeAndNode& other) const
	{
		return !(*this == other);
	}
	void Serialize(CArchive& ar);
	void Serialize(wxDataOutputStream& s) const;
	void Serialize(wxDataInputStream& s);

	void setLPlan(float val);
	void setLGen(float val);
	void setAPlan(float val);
	void setAProfFix(float val);
	void setAProf(float val);
	void setUklon(float val);
	void calc_angles();
};


inline float DegToRad(float x)
{
    constexpr float s = float(M_PI) / 180;
    return x * s;
}

inline float RadToDeg(float x)
{
    constexpr float s = 180 / float(M_PI);
    return x * s;
}

inline float Round(float x, int N)
{
	float f = 1.0f;
	for(int i = 0; i < N; i++)
		f *= 10.0f;
	return x > 0 ? int(x * f + 0.5f) / f : int(x * f - 0.5f) / f;
}

class CStartPPDoc;




