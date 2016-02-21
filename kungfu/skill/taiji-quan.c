// taiji-quan.c ̫��ȭ
// ���Ӳ�ͬ���ܼ�����Ӧ��ѧϰ����ʹ����������, by ReyGod, in 12/17/1996
//      query_skill_name() and query_action()

inherit SKILL;

mapping *action = ({
([	"action" : "$Nʹһ�С���ȸβ����˫�ֻ��˸���Ȧ������$n��$l",
	"force" : 100,
	"dodge" : 50,
	"skill_name" : "��ȸβ",
	"lvl" : 0,
	"damage_type" : "����"
]),
([	"action" : "$Nʹһ�С����ޡ��������������£���������ӳ�������$n��$l",
	"force" : 120,
	"dodge" : 48,
	"skill_name" : "����",
	"lvl" : 5,
	"damage_type" : "����"
]),
([	"action" : "$N���ֻ��գ������ɹ����ƣ���������ʹһ�С�������ʽ������$n��$l��ȥ",
	"force" : 140,
	"dodge" : 46,
	"skill_name" : "������ʽ",
	"lvl" : 10,
        "damage_type" : "����"
]),
([	"action" : "$N˫�ֻ������������ϣ��������£�ʹһ�С��׺����᡹���ֻ�$n�����ź�$l",
	"force" : 160,
	"dodge" : 44,
	"skill_name" : "�׺�����",
	"lvl" : 15,
        "damage_type" : "����"
]),
([	"action" : "$N��������ǰ���£�����΢ת������һ����Ȧ��ʹһ�С�§ϥ�ֲ���������$n��$l",
	"force" : 180,
	"dodge" : 42,
	"skill_name" : "§ϥ�ֲ�",
	"lvl" : 20,
        "damage_type" : "����"
]),
([	"action" : "$N�������������������ںϣ�ʹһ�С��ֻ����á�����$n��$l��ȥ",
	"force" : 200,
	"dodge" : 40,
	"skill_name" : "�ֻ�����",
	"lvl" : 25,
        "damage_type" : "����"
]),
([	"action" : "$N���ֱ��ƺ�����ǰ����ȭ�����´�����һ�С���׿�����������$n��$l",
	"force" : 220,
	"dodge" : 38,
	"skill_name" : "��׿���",
	"lvl" : 30,
        "damage_type" : "����"
]),
([	"action" : "$N���ǰ̤�벽������ʹһ�С������롹��ָ������$n��$l��ȥ",
	"force" : 240,
	"dodge" : 36,
	"skill_name" : "������",
	"lvl" : 35,
        "damage_type" : "����"
]),
([	"action" : "$N�С���ͨ�ۡ������һ���������������Ͼ�����Ʋ������$n��$l��ȥ",
	"force" : 260,
	"dodge" : 34,
	"skill_name" : "��ͨ��",
	"lvl" : 40,
        "damage_type" : "����"
]),
([	"action" : "$N��������ԣ�ת�����������·ֱ�ӳ�������ʹһ�С�б��ʽ��������$n��$l",
	"force" : 280,
	"dodge" : 32,
	"skill_name" : "б��ʽ",
	"lvl" : 45,
        "damage_type" : "����"
]),
([	"action" : "$N�����鰴������ʹһ�С��������š�����$n��$l��ȥ",
	"force" : 300,
	"dodge" : 30,
	"skill_name" : "��������",
	"lvl" : 50,
        "damage_type" : "����"
]),
([	"action" : "$N˫����ȭ����ǰ��󻮻���һ�С�˫����������$n��$l",
	"force" : 320,
	"dodge" : 28,
	"skill_name" : "˫����",
	"lvl" : 55,
        "damage_type" : "����"
]),
([	"action" : "$N�����黮������һ�ǡ�ָ�ɴ�������$n���ɲ�",
	"force" : 340,
	"dodge" : 26,
	"skill_name" : "ָ�ɴ�",
	"lvl" : 60,
        "damage_type" : "����"
]),
([	"action" : "$Nʩ��������ʽ�������ֻ���$n��$l�����ֹ���$n���ɲ�",
	"force" : 360,
	"dodge" : 24,
	"skill_name" : "����ʽ",
	"lvl" : 65,
        "damage_type" : "����"
]),
([	"action" : "$N�ɱ۴��֣�����ǰ����������ʹһ�С����֡�������$n��$l",
	"force" : 380,
	"dodge" : 22,
	"skill_name" : "����",
	"lvl" : 70,
        "damage_type" : "����"
]),
([	"action" : "$N������������ʹһ�С��𼦶���������$n��$l��ȥ",
	"force" : 400,
	"dodge" : 20,
	"skill_name" : "�𼦶���",
	"lvl" : 75,
        "damage_type" : "����"
]),
([	"action" : "$N�����ɹ����ƣ�˫���������ϣ�������ǰ�Ƴ�һ�С���̽����",
	"force" : 420,
	"dodge" : 18,
	"skill_name" : "��̽��",
	"lvl" : 80,
        "damage_type" : "����"
]),
([	"action" : "$N����ʹһʽ�С���Ů���󡹣�������$n��$l��ȥ",
	"force" : 440,
	"dodge" : 16,
	"skill_name" : "��Ů����",
	"lvl" : 85,
        "damage_type" : "����"
]),
([	"action" : "$N���־���ǰ��������ǰƲ����ʹһ�С�����Ʋ��������$n��$l��ȥ",
	"force" : 460,
	"dodge" : 14,
	"skill_name" : "����Ʋ��",
	"lvl" : 90,
        "damage_type" : "����"
]),
([	"action" : "$N�����鰴������ʹһ�С�ת�����ȡ�����$n��$l��ȥ",
	"force" : 480,
	"dodge" : 12,
	"skill_name" : "��������",
	"lvl" : 95,
        "damage_type" : "����"
]),
([	"action" : "$N�������ϻ�������������ʹһ�С�������������$n��$l��ȥ",
	"force" : 500,
	"dodge" : 10,
	"skill_name" : "��������",
	"lvl" : 100,
        "damage_type" : "����"
]),
([	"action" : "$Nʹһ�С��Դ���������§��ϥ���������´���$n��$l",
	"force" : 520,
	"dodge" : 8,
	"skill_name" : "�Դ�",
	"lvl" : 110,
        "damage_type" : "����"
]),
([	"action" : "$N˫���ȱ�����״�����طֿ������������£�һ�С�Ұ�����ס�����$n��$l�����Ŵ�ȥ",
	"force" : 480,
	"dodge" : 6,
	"skill_name" : "Ұ������",
	"lvl" : 120,
        "damage_type" : "����"
]),
([	"action" : "$N��������ǰ���£��ұ�΢����ʹһ�С�������ɽ������$n��$l��ȥ",
	"force" : 500,
	"dodge" : 4,
	"skill_name" : "������ɽ",
	"lvl" : 130,
        "damage_type" : "����"
]),
([	"action" : "$N˫�־��¸�����������ǰ����ʮ��״��һʽ��ʮ���֡�����$n��$l��ȥ",
	"force" : 520,
	"dodge" : 2,
	"skill_name" : "ʮ����",
	"lvl" : 140,
        "damage_type" : "����"
]),
([	"action" : "$N���̤һ���鲽��˫�ֽ����ʮ��ȭ��һ�С��������ǡ�����$n��$l��ȥ",
	"force" : 540,
	"dodge" : 0,
	"skill_name" : "��������",
	"lvl" : 150,
        "damage_type" : "����"
]),
([	"action" : "$N��������ڳ���������ֱ���ұ�΢����ʹһ�С���������$n��$l�����Ŵ�ȥ",
	"force" : 560,
	"dodge" : -2,
	"skill_name" : "�����",
	"lvl" : 160,
        "damage_type" : "����"
]),
([	"action" : "$N˫���쿪������Ϊ�ᣬ������������һ����Բ����\nһ�С�ת������������$n�������¶�������������Ӱ֮��",
	"force" : 580,
	"dodge" : -4,
	"skill_name" : "ת������",
	"lvl" : 170,
        "damage_type" : "����"
]),
([	"action" : "$N˫����ȭ�����ֻ����������ʣ����ֻ�����ǰ�Ƴ���\nȭ�������һ�С��乭�仢����ֱ��$n���Ѷ�ȥ",
	"force" : 600,
	"dodge" : -6,
	"skill_name" : "�乭�仢",
	"lvl" : 180,
        "damage_type" : "����"
]),
([	"action" : "$N˫������ǰ���ƣ��ɸ�����ǰ�����Ƴ���һ�С�����Ʊա���һ�ɾ���ֱ��$n",
	"force" : 620,
	"dodge" : -8,
	"skill_name" : "����Ʊ�",
	"lvl" : 200,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��̫��ȭ������֡�\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("���̫���񹦻�򲻹����޷�ѧ̫��ȭ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷���̫��ȭ��\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

/* ----------------
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
-------------------*/

mapping query_action(object me, object weapon)
{
	int i, level;
    level   = (int) me->query_skill("taiji-quan",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������̫��ȭ��\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-quan/" + action;
}