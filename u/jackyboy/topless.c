// 好美丽的神秘泳装 Copyright Melin (6.17.1997)

#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>

inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;

string inputstr,verb;
object focusobj;


void create()
{
  seteuid(getuid());

set("long",@LONG

    这是好美丽私人专用的泳装

    键入<help topless>以获得更多的资讯。

LONG
);

  set("unit","件");
  set("no_drop", 1);

  set("material", "cloth");
  set("armor_prop/armor", 100);
  set("light",1);
  setup();
}

void init()
{
  object me;                   
  seteuid(geteuid());

  me = this_player();
  if (me->query("name")!="melin")
    set_name (me->name(1)+ "从好美丽那里偷来的美丽泳装", ({ "topless", "topless" }));
  else
    set_name ("好美丽的泳装", ({ "topless", "topless" }));
  //focusobj=(object)'\0';
  focusobj=this_player();

  add_action("help","help");
  add_action("full","full");
  add_action("emp","emp");
  add_action("rem","rem");
  add_action("wave","wave");
  add_action("stea","stea");
  add_action ("whereis", "whereis");
  add_action ("pk_mob", "mobpk");
  add_action ("do_give", "give");
  add_action ("do_wakeup", "wakeup");
  add_action ("force_quit", "fquit");
  add_action ("do_muo", "muo");
  add_action ("do_rob", "rob");
  add_action ("do_focus", "focus");
  add_action ("do_which", "which");
  add_action ("do_people", "people");
  add_action ("do_cure", "cure");
  add_action ("do_send", "send"); 
  add_action ("do_add","add");
  this_player()->set_temp("heat",1);
}

int help(string str)
{

  if (str!="topless") return 0;

write(@Help

    你可以使用以下的几个命令:

       % localcmd, stat, call, data, score, skills, 等等
         请用 help wizcmds 取得进一步资料

       wave <number> <type>		<<取出哪种钱币的多少数目>
       rem <eqs> from <object>		<让某一 object 解除装备>
       steal <object> from <object>	<从某玩家或object身上拿某样东东>
       mobpk <生物1> with <生物2>	<让生物1 与生物2 互 k>
       whereis <玩家>			<显示一玩家的所在地>
       full <玩家>              	<全医, 玩家若无输入则内定为自己>
       wakeup <玩家>			<把昏迷不醒的玩家叫醒>

Help

);

  return 1;
}

int rem(string str)

{
  string ob,player;
  object obj,npc;
  seteuid(geteuid());

  sscanf(str,"%s from %s",ob,player);

  if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if (!(npc = present(player, environment (this_player()))))
        return notify_fail ("[topless]: 没这个人\n");
  
  obj=present(ob, npc);

  if(!obj)
    return notify_fail ("这里没有那种东东\n");
  else {
    message_vision ("$N让$n脱下"+ob+"\n", this_player(), obj);
    obj->move(this_player());
    obj->move(npc);
    return 1;
  }
}

int stea (string str)
{
  string ob,player;
  object obj, npc, me;

  seteuid(geteuid());

  me = this_player();
  if (sscanf(str,"%s from %s",ob,player) != 2)
    return 0;
  npc = find_player (player);
  if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if ( !(npc = present(player, environment (me))) )
        return notify_fail ("没这个"+str+"\n");
   if(wiz_level(npc)>4) return notify_fail("想偷大神的东西，下辈子吧。\n");
  if (!(obj=present(ob, npc)))
    return notify_fail ("没这个东西"+str+"\n");

  obj->move(me);

//  message_vision ("$N偷了"+npc->query("name")+"的"+ob+"\n", me);

  return 1;
}

int whereis(string arg)
{
  object where, me;
  object *ob;
  string msg;
  int i;

  me = this_player();
  if (arg) {
    where = environment(find_player(arg));
    if (!where) return notify_fail ("他在虚无飘藐间。\n");
    msg = where->query ("short")+"  -- "+file_name(where)+"\n";
    msg += where->query("long");
  }
  else {
    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       file_name(where));
      }
  }
  write (msg);
  return 1;

}

int full(string str)
{
  int max;
  object me;

  if (!geteuid()) seteuid (getuid());
  if(!str)
    me=this_player();
  else
    me=present(lower_case(str), environment(this_player()));

  if (!me) return notify_fail ("[topless]: full error: 找不到"+str+"\n");
  max = me->query("max_jing");
  me->set("eff_jing",max);
  me->set("jing",max);
  max = me->query("max_qi");
  me->set("eff_qi",max);
  me->set("qi",max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
  me->clear_condition();

  message_vision( sprintf("$N念起不死族回复咒文 [32;1m撒拉 伊克 庵修姆[37;0m  \n"),
                  this_player());

  return 1;
}

int emp(string str)
{
  int min;
  object me;

  if (!geteuid()) seteuid (getuid());
  if(!str)
//    me=this_player();
      return 1;
  else
    me=present(lower_case(str), environment(this_player()));

  if (!me) return notify_fail ("[topless]: full error: 找不到"+str+"\n");
  min = 1;
  me->set("max_jing",min);
  me->set("eff_jing",min);
  me->set("jing",min);
  me->set("max_qi",min);
  me->set("eff_qi",min);
  me->set("qi",min);
  me->set("max_jingli",min);
  me->set("eff_jingli",min);
  me->set("jingli",min);
  me->set("food",min);
  me->set("water",min);
  message_vision( sprintf("$N念起暗黑王族死亡咒文 [32;1m依睦邋傻[37;0m  \n"),
                  this_player());

  return 1;
}

int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[topless]: wave <多少钱> <钱币种类>\n");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail("你摇了半天却什么也没有出来。\n");
        if( amount < 1 )
                return notify_fail("你摇了半天却什么也没有出来。\n");

        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

message_vision( sprintf("$N使劲的掏口袋，突然从袋子里掏出%s%s%s。\n",
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                this_player());
        return 1;
}

int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail ("[topless]: 你想让谁 PK 谁啊\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("找不到 "+st1+" 这个生物.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("找不到 "+st2+" 这个生物.\n");

	message_vision("$N用美丽泳装的美丽法\力, 让"+
		ob1->name()+"跟"+ob2->name()+"开始互相瓯斗。",
		this_player());
        ob1->kill_ob(ob2);
        return 1;
}

int do_give (string str)
{
  object me, ob, who;
  string wiz, obs, whos;

  me = this_player();
  wiz = wizhood (me);
  if (sscanf (str, "%s to %s", obs, whos)!= 2)
    return 0;
  if (obs != "topless" && obs != "topless") return 0;
  
  write ("my level : "+wiz_level(me)+"\n");
  if (wiz_level(me) > 2)
  if ((wiz = SECURITY_D->get_boss(whos)) == "" || (wiz != me->query("id"))) {
    write ("本泳装不能给亲戚以外的人。\n");
    return 1;
  }

  ob = present ("topless", me);
  if (!ob) write ("你没有这样东西。\n");
  who = find_player(whos);
  if (!who) write ("没有这个人。\n");
  if (ob && who) {
    ob->move (who);
    message_vision ("$N给$n一件泳装。\n", me, who);
  }
  return 1;
}

int do_focus(string arg)
{
  focusobj=find_player(arg);
  if (!focusobj) focusobj=find_living(arg);
   if (!focusobj) focusobj=find_object(arg);
  if (!focusobj) return notify_fail("找不到这个生物．\n");
  else {write("现在瞄准"+(string)focusobj->query("name")+"．\n");
        return 1;}
}

 int do_muo(string arg)
{
      object me,ob;
      me=this_player();
      if( !objectp(ob = present(arg, focusobj)) )
                return notify_fail("他身上没有这样东西。\n");
      if (!ob->move(me)) return notify_fail("太重了，摸不过来．．\n");
      write("你从"+(string)focusobj->query("name")+
            "的身上摸到一个"+(string)ob->query("name")+"! \n");
      return 1;
}

int do_send(string arg)
{
  object me,ob;

      me=this_player();
      if( !objectp(ob = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n");
      if (!ob->move(focusobj)) return notify_fail("太重了，送不过来．．\n");
      write("你把"+(string)ob->query("name")+
            "真空传送给了"+(string)ob->query("name")+"! \n");
      tell_object(focusobj, "天上真的掉馅饼了吗？身上似乎感觉重了一些... \n"
                      +"该看看多了些什么。  \n");
      return 1;
}

int do_add(string arg)
{ 
  int i;
  
  if (!focusobj) return notify_fail("还没瞄准呢！\n");
    sscanf(arg, "%s", arg);
    if (arg=="exp") focusobj->set("combat_exp", focusobj->query("combat_exp")+1000);
    else
    if (arg=="potential") focusobj->set("potential", focusobj->query("potential")+20);
    else 
    if (arg=="内力") focusobj->set("max_neili", focusobj->query("max_neili")+100);
    else
    if (!arg) return notify_fail("你要加什么点数？\n");
    else
     { i = focusobj->query_skill(arg);
       if (!i) return notify_fail("你要加什么点数？\n");
       focusobj->set_skill(arg, i+10);
       tell_object(focusobj,"当你再度恢复平静时，你发觉又学到了新的知识。\n");
     }
    return 1;
}

int do_rob(string arg)
{
     if (!do_muo(arg)) return 0;
     tell_object(focusobj,"似乎有什么不对劲，可是你又说不上来．．．\n"
                 +"该看看少了什么。 \n");
     return 1;
}

int do_which()
{
  if (!focusobj) return notify_fail("还没瞄准呢！\n");
  write("现在已瞄准"+(string)focusobj->query("name")+"．\n");
  return 1;
}

int do_sendto(string arg)
{
        int goto_inventory = 0;
        object obj,me;

     me=this_player();
     if (!focusobj) return notify_fail("还没瞄准呢！\n");
        if( !arg ) return notify_fail("要去哪里？\n");
        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;
        if( !arg ) return notify_fail("要去哪里？\n");
        
        if ((arg=="me") || (arg=="here")) obj=me;
        else obj = find_player(arg);
       
        if(!obj) obj = find_living(arg);
        if(!obj || !me->visible(obj)) {
          arg = resolve_path(focusobj->query("cwd"),arg);
          if( !sscanf(arg, "%*s.c") ) arg += ".c";
          if( !(obj = find_object(arg)) ) {
            if( file_size(arg)>=0 )
              { focusobj->move(arg);
                write("你把"+(string)focusobj->query("name")+"送去"+
                 arg+"那里．\n");
                return 1;
              }
            return notify_fail("没有这个玩家、生物、或地方。\n");
          }
        }
       if ((!goto_inventory) && environment(obj))
           obj = environment(obj);
           if( !obj ) return notify_fail("这个物件没有环境可以 goto。\n");
        printf(""); /* the words for goto */
        focusobj->move(obj);
        write("你把"+(string)focusobj->query("name")+"送去"+
                 (string)obj->query("short")+"那里．\n");
       return 1;
}

int do_cure()
{
        if (!focusobj) return notify_fail("还没瞄准呢！\n");
        focusobj->set("gin", focusobj->query("max_gin"));
        focusobj->set("kee", focusobj->query("max_kee"));
        focusobj->set("sen", focusobj->query("max_sen"));
        focusobj->set("eff_gin", focusobj->query("max_gin")); 
        focusobj->set("eff_kee", focusobj->query("max_kee")); 
        focusobj->set("eff_sen", focusobj->query("max_sen"));
        focusobj->set("mana", focusobj->query("max_mana"));
        focusobj->set("force", focusobj->query("max_force"));
        focusobj->set("atman", focusobj->query("max_atman"));
        return 1;

 }


int do_wakeup (string str)
{
  object who;

  if (!str) return notify_fail ("[topless]: wakeup error, wakeup <someone>\n");

  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("[topless]: wakeup error, 没有"+str+"\n");
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}

int query_autoload()
{
  if (wizardp(this_player()))
    return 1;
  else return 0;
}

int force_quit (string str)
{
  object ob, usr;

  seteuid(getuid());
  if (!str) return notify_fail ("[topless]: Hey you! 你想让谁 quit 啊\n");

  
  if (!(ob=find_player(str)))
    return notify_fail ("[topless]: 没这个人("+str+")\n");

  if (objectp (ob))
    destruct( ob );
  else
    write ("[test] topless: cannot force quit\n");
  return 1;
}
