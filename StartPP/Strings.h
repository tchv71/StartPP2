﻿#ifndef STRINGS_H
#define STRINGS_H

#define IDS_NODE_BEG            _T("Узел начала")
#define IDS_NODE_BEG_C          _T("Узел начала участка")
#define IDS_NODE_END            _T("Узел конца")
#define IDS_NODE_END_C          _T("Узел конца участка")
#define IDS_PIPE_TYPE           _T("Тип участка")
#define IDS_PODZEM              _T("Подземный")
#define IDS_NADZEM              _T("Надземный")
#define IDS_GEOM                _T("Геометрия")
#define IDS_PROJ_X              _T("ПроекцияX, м")
#define IDS_PROJ_X_C            _T("Проекция участка на ось X")
#define IDS_PROJ_Y              _T("ПроекцияY, м")
#define IDS_STATUS_PANE1        _T("Панель 1")
#define IDS_STATUS_PANE2        _T("Панель 2")
#define IDS_TOOLBAR_STANDARD    _T("Стандартная")
#define IDS_TOOLBAR_CUSTOMIZE   _T("Настройка...")
#define IDS_PROJ_Y_C            _T("Проекция участка на ось Y")
#define IDS_PROJ_Y2             _T("ПроекцияY, м")
#define IDS_APROF_C             _T("Угол в профиле (азимутальный)")
#define IDS_UKLON               _T("Уклон, 1/1000")
#define IDS_UKLON_C             _T("Уклон трубопровода (1000 = 45 град)")
#define IDS_DIAM                _T("Диаметр трубы, мм")
#define IDS_DIAM_C              _T("Диаметр трубы")
#define IDS_MATERIAL            _T("Материал трубы")
#define IDS_MATERIAL_C          _T("Материал трубы")
#define ID_PROP_SV              _T("Вставка сварного отвода\nСварной отвод")
#define ID_PROP_OTV_IZ          _T("Вставка изогнутого отвода в узле\nОтвод изогнутый")
#define ID_PROP_ARM             _T("Вставка арматуры в узле\nАрматура")
#define ID_EXPAND_ALL           _T("Распахнуть все ветки свойств\nРаспахнуть все")
#define IDS_FILE_VIEW           _T("Представление файлов")
#define IDS_CLASS_VIEW          _T("Представление классов")
#define IDS_PIPE_TABLE_WND      _T("Таблица труб")
#define IDS_PROPERTIES_WND      _T("Свойства")
#define IDS_NOTO                _T("Толщина стенки трубы, мм")
#define IDS_MN_NO_PIPES_OUT     _T("Из узла %d не выходит ни один участок!")
#define IDS_EXPLORER            _T("Проводник")
#define IDS_EDIT_MENU           _T("Редактировать")
#define IDS_MN_2_PIPES_OUT      _T("Из узла %d выходит 2 или более участков!")
#define IDS_MN_NULL_LEN         _T("Нулевая длина одного из участков")
#define IDS_MN_IZLOM            _T("Точка излома в узле %g")
#define IDS_MN_TOO_MUCH_LEN     _T("Расстояние превышает длину участка!")
#define IDS_NODE_EXISTS         _T("Узел %d уже существует")
#define IDS_MORE_ONE_BLANK_LINE _T("Более одной пустой строки")
#define IDS_PIPES_MUSTBE_MORE1  _T("Число участков должно быть больше 1")
#define IDS_DIST_SUM_MORE_PIPE_LEN _T("Сумма расстояний превышает длину участка")
#define IDS_PDD_AIR             _T("воздуx (газ)")
#define IDS_PDD_WATER           _T("вода")
#define IDS_PDD_NO_PERFORM      _T("не проводить")
#define IDS_PDD_RD_10_400_01_PDN _T("РД 10-400-01 (режим ПДН) Тепловые сети")
#define IDS_PDD_RD_10_400_01_PDK _T("РД 10-400-01 (режим ПДК) Тепловые сети")
#define IDS_F_RADA              _T("Рабочее давление")
#define IDS_F_DABI              _T("Давление испытания")
#define IDS_F_DIAM_KOZH         _T("Диаметр кожуха изоляции")
#define IDS_F_VIZA              _T("Высота засыпки грунта (начало)")
#define IDS_F_VIZA2             _T("Высота засыпки грунта (конец)")
#define IDS_F_SHTR              _T("Ширина траншеи")
#define IDS_F_PELI              _T("Определять лин. перемещения")
#define IDS_F_PEUG              _T("Определять угл. перемещения")
#define IDS_F_LEN               _T("Длина участка")
#define IDS_F_APROF             _T("Угол в профиле")
#define IDS_DEL_PIPES_Q         _T("Удалить %d участков?")
#define IDS_MN_NO_PIPES_UZ      _T("В узел %d нет входящих участков!")
#define IDS_BUILD_TAB           _T("Сборка")
#define IDS_DEBUG_TAB           _T("Отладка")
#define IDS_FIND_TAB            _T("Найти")
#define IDS_MN_2PIPES_IN        _T("В узел %d входит 2 или более участков!")
#define ID_ZOOM_IN              _T("Увеличение масштаба\nУвеличить")
#define ID_ZOOM_OUT             _T("Уменьшение масштаба\nУменьшить")
#define ID_ZOOM_ALL             _T("Показать весь документ\nПоказать все")
#define ID_ZOOM_WIN             _T("Масштабирование рамкой\nМасшт. рамкой")
#define ID_PAN                  _T("Панорамирование\nПанорамирование")
#define ID_ROTATE               _T("Вращение схемы\nВращение")
#define ID_SELECT               _T("Выбор участка\nВыбор")
#define ID_VIEW_NODE_NUMS       _T("Показать номера узлов\nНомера узлов")
#define ID_VIEW_SIZES           _T("Показать размеры\nРазмеры")
#define ID_VIEW_APROF           _T("Показать углы в профиле\nУглы в профиле")
#define ID_VIEW_ELEMENTS        _T("Показать элементы в узлах\nЭлементы")
#define ID_VIEW_NODES           _T("Показать отметки узлов\nУзлы")
#define ID_NEW_PIPE             _T("Создать новый участок\nНовый участок")
#define ID_DEL_PIPE             _T("Удалить участки\nУдалить участки")
#define ID_COPY_PIPE_PARAMS     _T("Копирование параметров участка\nКопирование параметров")
#define ID_NEW_NODE             _T("Ввести новые узлы на участке\nРазбить участок")
#define ID_INVERT_PIPE          _T("Поменять местами начальный и конечный узел участка\nИнвертировать узлы")
#define ID_MOVE_NODE            _T("Передвинуть узел на прямом участке\nПередвинуть узел")
#define ID_RENUM_PIPES          _T("Перенумеровать узлы на схеме\nПеренумеровать")
#define ID_MULT_PIPE            _T("Размножить участок\nРазмножить участок")
#define ID_VIEW_3DVIEWS_TOP     _T("Показать модель сверху\nПлан")
#define ID_VIEW_3DVIEWS_BOTTOM  _T("Показать модель снизу\nСнизу")
#define ID_VIEW_3DVIEWS_LEFT    _T("Показать модель слева\nСлева")
#define ID_VIEW_3DVIEWS_RIGHT   _T("Показать модель справа\nСправа")
#define ID_VIEW_3DVIEWS_FRONT   _T("Показать модель спереди\nСпереди")
#define ID_VIEW_3DVIEWS_BACK    _T("Показать модель сзади\nСзади")
#define ID_VIEW_3DVIEWS_SW_ISO  _T("Показать модель в юго-западной изометрии\nЮЗ изометрия")
#define ID_VIEW_3DVIEWS_SE_ISO  _T("Показать модель в юго-восточной изометрии\nЮВ изометрия")
#define ID_VIEW_3DVIEWS_NE_ISO  _T("Показать модель в северо-восточной изометрии\nСВ изометрия")
#define ID_VIEW_3DVIEWS_NW_ISO  _T("Показать модель в северо-западной изометрии\nСЗ изометрия")
#define ID_Spusk                _T("Вставка спускников  и ответвлений\nСпуск. и отв.")
#define ID_ADD_SCHEM            _T("Вставка другой схемы в текущую")
#define ID_PROP_SK              _T("Вставка скользящей опоры в узле\nСкользящая опора")
#define ID_PROP_MERT            _T("Вставка мертвой опоры в узле\nМёртвая опора")
#define ID_PROP_NAPR            _T("Вставка направляющей опоры в узле\nНаправляющая опора")
#define ID_PROP_OTV_SV          _T("Вставка сварного отвода в узле\nОтвод сварной")
#define ID_SHOW_OGL             _T("Показ модели в 3D виде\n3D вид")
#define ID_UNDO                 _T("Отмена последнего действия\nОтменить")
#define ID_REDO                 _T("Повторное выполнение последнего действия\nВернуть")
#define ID_IMPORT_DBF           _T("Импорт схемы трубопровода из файла *.DBF")
#define ID_PIPE_DESC            _T("Отобразить окно параметров расчета\nПараметры расчета")
#define ID_EXPORT_INI           _T("Экспорт текущей схемы в файл открытого формата Старт *.ini")
#define IDS_NOTO_C              _T("Номинальная толщина стенки трубы")
#define IDS_RATO                _T("Технологическое утонение, мм")
#define IDS_RATO_C              _T("Технологическое утонение")
#define IDS_RADA                _T("Расчетное давление, кгс/кв.см")
#define IDS_RADA_C              _T("Расчетное давление")
#define IDS_DABI                _T("Давление испытания, кгс/кв.см")
#define IDS_DABI_C              _T("Давление испытания")
#define IDS_RATE                _T("Расчетная температура, °C")
#define IDS_RATE_C              _T("Расчетная температура")
#define IDS_POG_VESA            _T("Погонные веса, кгс/м")
#define IDS_VETR                _T("Трубы, кгс/м")
#define IDS_VETR_C              _T("Погонный вес трубы")
#define IDS_VEIZ                _T("Изоляции, кгс/м")
#define IDS_VEIZ_C              _T("Погонный вес изоляции")
#define IDS_VEPR                _T("Продукта, кгс/м")
#define IDS_VEPR_C              _T("Погонный вес продукта")
#define IDS_ADDITIONAL          _T("Дополнительные")
#define IDS_KOPE                _T("Коэф. прочн. на давл. сварн. соединения")
#define IDS_KOPE_C              _T("Коэффициент прочности сварного соединения на давление")
#define IDS_KOPR                _T("Коэф. прочн. на изгиб сварн. соединения")
#define IDS_KOPR_C              _T("Коэффициент прочности сварного соединения на изгиб")
#define IDS_ADD_NAGR            _T("Дополнительные нагрузки, кгс/м")
#define IDS_NAGV                _T("Сила от веса, кгс/м")
#define IDS_NAGV_C              _T("Сила от веса")
#define IDS_NAGX                _T("X невесовая сила, кгс/м")
#define IDS_NAGX_C              _T("Невесовая сила по оси X")
#define IDS_NAGY                _T("Y невесовая сила, кгс/м")
#define IDS_NAGY_C              _T("Невесовая сила по оси Y")
#define IDS_NAGZ                _T("Z невесовая сила, кгс/м")
#define IDS_NAGZ_C              _T("Невесовая сила по оси Z")
#define IDS_GRUNT               _T("Грунт")
#define IDS_DIAM_KOZHUX         _T("Диаметр кожуха, мм")
#define IDS_DIAM_KOZHUX_C       _T("Диаметр кожуха изоляции")
#define IDS_GLUB                _T("Глубина заложения, м")
#define IDS_BEG_GLUB            _T("в начале участка, м")
#define IDS_BEG_GLUB_C          _T("В начале участка")
#define IDS_END_GLUB            _T("в конце участка, м")
#define IDS_END_GLUB_C          _T("В конце участка")
#define IDS_VIZA                _T("Высота засыпки, м")
#define IDS_SHTR                _T("Ширина траншеи, м")
#define IDS_SHTR_C              _T("Ширина траншеи")
#define IDS_GRUNT_TYPE          _T("Тип грунта")
#define IDS_GRUNT_UP            _T("Сверху")
#define IDS_GRUNT_UP_C          _T("Тип грунта засыпки (сверху)")
#define IDS_GRUNT_OSN           _T("Oснования")
#define IDS_GRUNT_OSN_C         _T("Тип грунта основания")
#define IDS_GRUNT_SIDE          _T("Cбоку")
#define IDS_GRUNT_SIDE_C        _T("Тип грунта сбоку")
#define IDS_NODE                _T("Узел")
#define IDS_NODE_C              _T("Узел конца участка")
#define IDS_NONE                _T("Нет")
#define IDS_ARMAT               _T("Арматура")
#define IDS_OTVIZ               _T("Oтвод изогнутый")
#define IDS_OTVSV               _T("Oтвод сварной")
#define IDS_OTVFL               _T("Oтвод фланцевый")
#define IDS_KO                  _T("Kомпенсатор осевой")
#define IDS_KU                  _T("Kомпенсатор угловой")
#define IDS_TR                  _T("Тройник сварной")
#define IDS_VREZKA              _T("Сварная врезка")
#define IDS_IZD                 _T("Изделие")
#define IDS_IZD_C               _T("Тип изделия в узле")
#define IDS_AR_LEN              _T("Длина, м")
#define IDS_AR_LEN_C            _T("Длина арматуры")
#define IDS_AR_VES              _T("Вес, кг")
#define IDS_AR_VES_C            _T("Вес арматуры")
#define IDS_OTV_RAD             _T("Радиус, м")
#define IDS_OTV_RAD_C           _T("Радиус отвода")
#define IDS_OTV_VES             _T("Вес, кг")
#define IDS_OTV_VES_C           _T("Вес отвода")
#define IDS_OTV_MAT             _T("Материал")
#define IDS_OTV_MAT_C           _T("Материал отвода")
#define IDS_OTV_NOTO            _T("Номинальная толщина стенки, мм")
#define IDS_OTV_NOTO_C          _T("Номинальная толщина стенки отвода")
#define IDS_OTV_RATO            _T("Технологическое утонение, мм")
#define IDS_OTV_RATO_C          _T("Технологическое утонение стенки отвода")
#define IDS_KO_SEFF             _T("Эфф. площадь, кв.мм")
#define IDS_KO_SEFF_C           _T("Эффективная площадь осевого компенсатора")
#define IDS_KO_OS_HOD           _T("Осевой ход, мм")
#define IDS_KO_OS_HOD_C         _T("Осевой ход компенсатора")
#define IDS_KO_PODATL           _T("Податливость, мм/кг")
#define IDS_KO_PODATL_C         _T("Податливость осевого компенсатора")
#define IDS_KU_PODATL           _T("Податливость, рад/кг")
#define IDS_KU_PODATL_C         _T("Податливость углового компенсатора")
#define IDS_KU_LEN              _T("Длина, м")
#define IDS_KU_LEN_C            _T("Длина углового компенсатора")
#define IDS_TR_MAT              _T("Материал")
#define IDS_TR_MAT_C            _T("Материал тройника")
#define IDS_TR_VES              _T("Вес, кг")
#define IDS_TR_VES_C            _T("Вес тройника")
#define IDS_MAGISTRAL           _T("Магистраль:")
#define IDS_MAG_NOTO            _T("Номинальная толщина")
#define IDS_MAG_NOTO_C          _T("Номинальная толщина стенки магистрали")
#define IDS_MAG_RATO            _T("Технологич. утонение")
#define IDS_MAG_RATO_C          _T("Технологическое утонение")
#define IDS_MAG_LEN             _T("Длина магистрали")
#define IDS_MAG_LEN_C           _T("Длина магистрали")
#define IDS_OTV                 _T("Ответвление:")
#define IDS_OTV_DIAM            _T("Диаметр, мм")
#define IDS_OTV_DIAM_C          _T("Диаметр ответвления")
#define IDS_OSN                 _T("Основные")
#define IDS_FORMAT_PIPE         _T("Участок (%g-%g)")
#define IDS_FORMAT_NODE         _T("Узел (%g)")
#define IDS_FORMAT_MANY_PIPES   _T("Несколько участков/узлов:")
#define IDS_FORMAT_NODE2        _T("Узел (%d)")
#define IDS_FORMAT_PIPE2        _T("Участок (%d-%d)")
#define IDS_PODJOM              _T("Подъем")
#define IDS_OPUSK               _T("Опуск")
#define IDS_FORMAT_UCH_UZL      _T("Участков: %d  Узлов: %d")
#define IDS_FORMAT_PIPE_EXISTS  _T("Участок %d - %d уже существует")
#define IDS_ARMAT_TABLE         _T("Таблица арматуры")
#define IDS_STRING270           _T("Таблица арматуры")
#define IDS_AT_DIAM             _T("Диам.")
#define IDS_PT_ROTV             _T("Rотв, м")
#define IDS_PT_VESARM           _T("Вес арм., кг")
#define IDS_PT_MATOTV           _T("Мат-л отв")
#define IDS_PT_SOTV             _T("Sотв, мм")
#define IDS_PT_C1OTV            _T("C1отв, мм")
#define IDS_PT_SEFF             _T("Sэфф, мм")
#define IDS_PT_KPOD             _T("Кпод, м")
#define IDS_OTVL_NOTO           _T("Номинальная толщина")
#define IDS_OTVL_NOTO_C         _T("Номинальная толщина стенки ответвления")
#define IDS_OTVL_RATO           _T("Технологич. утонение")
#define IDS_OTVL_RATO_C         _T("Технологическое утонение")
#define IDS_OTVL_VYS            _T("Высота, мм")
#define IDS_OTVL_VYS_C          _T("Высота ответвления")
#define IDS_NAKL                _T("Накладка:")
#define IDS_NAKL_NOTO           _T("Номинальная толщина")
#define IDS_NAKL_NOTO_C         _T("Номинальная толщина накладки")
#define IDS_NAKL_SHIR           _T("Ширина накладки")
#define IDS_NAKL_SHIR_C         _T("Ширина накладки")
#define IDS_VR_KOPR             _T("Коэф. прочн. сварного соединения")
#define IDS_VR_KOPR_C           _T("Коэфициент прочности сварного соединения")
#define IDS_VR_NAKL             _T("Накладки:")
#define IDS_VR_NAKL_NOTO        _T("Толщина, мм")
#define IDS_VR_NAKL_NOTO_C      _T("Толщина накладки")
#define IDS_VR_NAKL_SHIR        _T("Ширина, мм")
#define IDS_VR_NAKL_SHIR_C      _T("Ширина накладки")
#define IDS_MERT                _T("Мертвая")
#define IDS_SK                  _T("Скользящая")
#define IDS_NAPR                _T("Направляющая")
#define IDS_UPR                 _T("Упругая")
#define IDS_ZHESTK_PODV         _T("Жесткая подвеска")
#define IDS_OPOR                _T("Опора")
#define IDS_OPOR_C              _T("Тип опоры в узле")
#define IDS_MERT_O              _T("Мертвая опора")
#define IDS_SK_O                _T("Скользящая опора")
#define IDS_NAPR_O              _T("Направляющая опора")
#define IDS_SK_KOTR             _T("Коэфф. трения")
#define IDS_SK_KOTR_C           _T("Коэффициент трения в опоре")
#define IDS_UPR_O               _T("Упругая опора")
#define IDS_UPR_NTG             _T("Число тяг")
#define IDS_UPR_NTG_C           _T("Число тяг")
#define IDS_UPR_IZM_NAGR        _T("Изменение нагрузки, %")
#define IDS_UPR_IZM_NAGR_C      _T("Изменение нагрузки")
#define IDS_UPR_KZAP            _T("К-т запаса по нагрузке")
#define IDS_UPR_KZAP_C          _T("Коэффициент запаса по нагрузке")
#define IDS_UPR_PODD_US         _T("Поддерж. усилие, кг")
#define IDS_UPR_PODD_US_C       _T("Поддерживающее усилие")
#define IDS_UPR_PODATL          _T("Податливость, мм/кг")
#define IDS_ZHP_LEN_TYAGI       _T("Длина тяги, м")
#define IDS_ZHP_LEN_TYAGI_C     _T("Длина тяги")
#define IDS_RAST                _T("Растяжение")
#define IDS_SG                  _T("Сжатие")
#define IDS_DEF                 _T("Деформация")
#define IDS_DEF_C               _T("Тип деформации в узле")
#define IDS_DEF_RAST            _T("Растяжение, мм")
#define IDS_DEF_SG              _T("Сжатие, мм")
#define IDS_DEF_RSTSG_C         _T("Величина деформации, мм")
#define IDS_NAGR                _T("Нагрузки")
#define IDS_NAGR_VES_ADD        _T("Дополнительные весовые нагрузки")
#define IDS_UZ_SILVES           _T("Сила от веса, кг")
#define IDS_UZ_SILVES_C         _T("Сила от веса в узле")
#define IDS_UZ_MOMVESX          _T("Момент от веса вокруг X, кг·м")
#define IDS_UZ_MOMVESX_C        _T("Момент от веса вокруг X в узле")
#define IDS_UZ_MOMVESY          _T("Момент от веса вокруг Y, кг·м")
#define IDS_UZ_MOMVESY_C2       _T("Момент от веса вокруг Y в узле")
#define IDS_NAGR_NONVES_ADD     _T("Дополнительные невесовые нагрузки")
#define IDS_UZ_SILX             _T("Сила по оси X, кг")
#define IDS_UZ_SILX_C           _T("Невесовая сила по оси X")
#define IDS_UZ_SILY             _T("Сила по оси Y, кг")
#define IDS_UZ_SILY_C2          _T("Невесовая сила по оси Y")
#define IDS_UZ_SILZ             _T("Сила по оси Z, кг")
#define IDS_UZ_SILZ_C           _T("Невесовая сила по оси Z")
#define IDS_UZ_MOMX             _T("Момент вокруг оси X, кг·м")
#define IDS_UZ_MOMX_C           _T("Невесовой момент вокруг оси X")
#define IDS_UZ_MOMY             _T("Момент вокруг оси Y кг·м")
#define IDS_UZ_MOMY_C           _T("Невесовой момент вокруг оси Y")
#define IDS_UZ_MOMZ             _T("Момент вокруг оси Z кг·м")
#define IDS_UZ_MOMZ_C           _T("Невесовой момент вокруг оси Z")
#define IDS_UPR_PODATL_C        _T("Податливость")
#define IDS_PT_SHTR             _T("Шир.транш., м")
#define IDS_PT_PIPE_TYPE        _T("Тип трубы")
#define IDS_AT_S                _T("S, мм")
#define IDS_AT_C1               _T("C1, мм")
#define IDS_AT_ROTV             _T("Рад.отв.,мм")
#define IDS_AT_VESOTV           _T("Вес отв.,кг")
#define IDS_AT_LZADV            _T("Длина задв.,м")
#define IDS_AT_VESZADV          _T("Вес задв.,кг")
#define IDS_AT_NAGRMERT         _T("Нагр.мерт")
#define IDS_AT_NAGRSK           _T("Нагр.ск")
#define IDS_F_DIAM              _T("Диаметр трубы")
#define IDS_F_NAMA              _T("Материал трубы")
#define IDS_F_NTOS              _T("Ном.  толщина стенки трубы")
#define IDS_STRING284           _T("Технологическое утонение")
#define IDS_F_VETR              _T("Вес погонного метра трубы")
#define IDS_F_VEIZ              _T("Вес погонного метра изоляции")
#define IDS_F_VEPR              _T("Вес погонного метра продукта")
#define IDS_PDD_BY_WATER        _T("водой")
#define IDS_PDD_BY_AIR          _T("воздухом (газом)")
#define IDS_PDD_PERFORM         _T("проводить")
#define IDS_NORMA_OST           _T("ОСТ 108.764.01-80")
#define IDS_NORMA_MVN           _T("МВН 049-63")
#define IDS_NORMA_MN            _T("МН 3958-62")
#define IDS_NORMA_OST24         _T("ОСТ 24.125.109-01")
#define IDS_NORMA_LISEGA        _T("LISEGA")
#define IDS_WORK                _T("рабочее")
#define IDS_COLD                _T("холодное")
#define IDS_STRING330           _T("IDS")
#define IDS_PT_MAT              _T("Мат-л трубы")
#define IDS_PT_QTR              _T("qтр, кг/м")
#define IDS_PT_QI               _T("qи, кг/м")
#define IDS_PT_QP               _T("qп, кг/м")
#define IDS_PT_DIZ              _T("Dиз, мм")
#define IDS_PT_SIZ              _T("Sиз, мм")
#define IDS_PT_PODZ             _T("Подз.")
#define IDS_PT_NADZ             _T("Надз.")
#define IDS_PT_DEL_LINE_Q       _T("Удалить строку?")
#define IDS_DELETE_NODE_Q       _T("Удалить узел %d?")
#define IDS_MN_IZLOM1           _T("Точка излома в узле %d")
#define IDS_RENUM_NODES_Q       _T("Перенумеровать узлы на схеме?")
#define IDS_UNITE_NODES_Q       _T("После удаления участков нарушится связность трубопровода. Объединить узлы удаляемого фрагмента?")
#define IDS_F_RTOS              _T("Технологическое утонение")
#define IDS_TR_TABLE            _T("Таблица тройников")
#define IDS_C                   _T("C, мм")
#define IDS_DIAM_SHT            _T("Диам.шт")
#define IDS_S_SHT               _T("Sшт.")
#define IDS_C_SHT               _T("Сшт.")
#define IDS_VYS_SHT             _T("Выс.шт.")
#define IDS_SHIR_NAKL           _T("Шир.накл")
#define IDS_TOLSCH_NAKL         _T("Толщ.накл")
#define IDS_VES_TR              _T("Вес тройника")
#define IDS_KORPUS              _T("KORPUS")
#define R_MAINFRAME           _T("StartPP")
#define S_PROJ_Y_C2           _T("Проекция участка на ось Y")
#define R_StartPPTYPE         _T("\nStartPP\nStartPP\nStartPP Files (*.spf)\n.spf\nStartPP.Document\nStartPP.Document")
#define _WINDOW_MANAGER       _T("Окна...")
#define IDS_PROJ_Z              _T("ПроекцияZ, м")
#define IDS_PROJ_Z_C            _T("Проекция участка на ось Z")
#define IDS_LEN_PLAN            _T("Длина в плане, м")
#define IDS_LEN_PLAN_C          _T("Длина участка в плане")
#define IDS_LEN_GEN             _T("Длина общая, м")
#define IDS_LEN_GEN_C           _T("Длина участка")
#define IDS_APLAN_ABS           _T("Угол в плане абсолютный, град")
#define ID_DEL_NODE             _T("Удалить узел на прямом участке\nУдалить узел")
#define IDS_APLAN_ABS_C         _T("Угол в плане абсолютный")
#define IDS_APLAN_REL           _T("Угол в плане относительный, град")
#define IDS_APLAN_REL_C         _T("Угол в плане относительно предыдущего участка")
#define IDS_APROF               _T("Угол в профиле, град")
#define IDS_UNITE_NODES_Q       _T("После удаления участков нарушится связность трубопровода. Объединить узлы удаляемого фрагмента?")
#define IDS_PODJOM              _T("Подъем")
#define IDS_OPUSK               _T("Опуск")
#define IDS_FORMAT_PIPE_EXISTS  _T("Участок %d - %d уже существует")
#define IDS_PARTS_NOT_CONNECTED _T("Части выделенного сегмента не связаны между собой")
#define IDS_DEL_PIPES_Q         _T("Удалить %d участков?")
#define STR_OS                  _T("ос")
#define STR_OI                  _T("ои")
#define STR_OF                  _T("оф")
#define STR_AR                  _T("ар")
#define STR_MO                  _T("мо")
#define STR_SK                  _T("ск")
#define STR_NP                  _T("нп")
#define STR_KO                  _T("ко")
#define STR_KU                  _T("ку")
#define STR_RS                  _T("рс")
#define STR_SG                  _T("сж")
#define STR_PD                  _T("пд")
#define STR_PR                  _T("пр")
#define STR_TR                  _T("тр")
#define STR_SV                  _T("св")

#define LoadStr(x) x

#endif