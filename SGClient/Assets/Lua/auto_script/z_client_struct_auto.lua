--client_struct_auto.lua

CMDS_BASE = 0;
CMDC_BASE = 0;

CMDS_LOGIN = CMDS_BASE+1;
CMDS_LIST = CMDS_BASE+2;
CMDS_CREATE = CMDS_BASE+3;
CMDS_ENTERINFO = CMDS_BASE+4;
CMDS_DELETE = CMDS_BASE+5;
CMDS_HEART = CMDS_BASE+6;
CMDS_NOTIFY = CMDS_BASE+7;
CMDS_ACTORINFO = CMDS_BASE+8;
CMDS_ITEMUSE = CMDS_BASE+9;
CMDS_ITEMPUT = CMDS_BASE+10;
CMDS_ITEMSETTLE = CMDS_BASE+11;
CMDS_LOSTITEM = CMDS_BASE+12;
CMDS_GETITEM = CMDS_BASE+13;
CMDS_ITEMLIST = CMDS_BASE+14;
CMDS_ITEMINFO = CMDS_BASE+15;
CMDS_ADDMAPUNIT = CMDS_BASE+16;
CMDS_DELMAPUNIT = CMDS_BASE+17;
CMDS_UPDATEMAPUNIT = CMDS_BASE+18;
CMDS_MAPUNITSINGLE = CMDS_BASE+19;
CMDS_WORLDMAPINFO = CMDS_BASE+20;
CMDS_MAPUNITCORRDINATE = CMDS_BASE+21;
CMDS_ADDMARCHROUTE = CMDS_BASE+22;
CMDS_DELMARCHROUTE = CMDS_BASE+23;
CMDS_AWARDINFOLIST = CMDS_BASE+24;
CMDS_EXPERIENCE = CMDS_BASE+25;
CMDS_BODY = CMDS_BASE+26;
CMDS_BUILDINGLIST = CMDS_BASE+27;
CMDS_CHANGELEVY = CMDS_BASE+28;
CMDS_CHANGESILVER = CMDS_BASE+29;
CMDS_CHANGEWOOD = CMDS_BASE+30;
CMDS_CHANGEFOOD = CMDS_BASE+31;
CMDS_CHANGEIRON = CMDS_BASE+32;
CMDS_CHANGEPEOPLE = CMDS_BASE+33;
CMDS_CHANGEPRESTIGE = CMDS_BASE+34;
CMDS_CHANGEFRIENDSHIP = CMDS_BASE+35;
CMDS_CHANGEVIP = CMDS_BASE+36;
CMDS_CHANGTOKEN = CMDS_BASE+37;
CMDS_EQUIP = CMDS_BASE+38;
CMDS_EQUIPLIST = CMDS_BASE+39;
CMDS_EQUIPGET = CMDS_BASE+40;
CMDS_EQUIPLOST = CMDS_BASE+41;
CMDS_HERO = CMDS_BASE+42;
CMDS_HEROLIST = CMDS_BASE+43;
CMDS_HEROEXP = CMDS_BASE+44;
CMDS_HEROSOLDIERS = CMDS_BASE+45;
CMDS_HEROSTATE = CMDS_BASE+46;
CMDS_HEROREPLACE = CMDS_BASE+47;
CMDS_BUILDINGUPGRADEINFO = CMDS_BASE+48;
CMDS_BUILDING = CMDS_BASE+49;
CMDS_BUILDINGBARRACKS = CMDS_BASE+50;
CMDS_BUILDINGRES = CMDS_BASE+51;
CMDS_WORKER = CMDS_BASE+52;
CMDS_HEROGET = CMDS_BASE+53;
CMDS_BUILDINGGET = CMDS_BASE+54;
CMDS_BUILDINGBARRACKSGET = CMDS_BASE+55;
CMDS_BUILDINGRESGET = CMDS_BASE+56;
CMDS_SOLDIERS = CMDS_BASE+57;
CMDS_TRAININFO = CMDS_BASE+58;
CMDS_QUEST = CMDS_BASE+59;
CMDS_QUESTLIST = CMDS_BASE+60;
CMDS_QUESTAWARD = CMDS_BASE+61;
CMDS_FUNCTION = CMDS_BASE+62;
CMDS_CITYGUARD = CMDS_BASE+63;
CMDS_CITYGUARDLIST = CMDS_BASE+64;
CMDS_CITYGUARDSEC = CMDS_BASE+65;
CMDS_BUILDINGSMITHY = CMDS_BASE+66;
CMDS_CHANGENAME = CMDS_BASE+67;
CMDS_BUILDINGACTION = CMDS_BASE+68;
CMDS_LEVYINFO = CMDS_BASE+69;
CMDS_CHAT = CMDS_BASE+70;
CMDS_CHATLIST = CMDS_BASE+71;
CMDS_SYSTALKID = CMDS_BASE+72;
CMDS_SYSTALK = CMDS_BASE+73;
CMDS_BATTLEPOWER = CMDS_BASE+74;
CMDS_TECHCHANGE = CMDS_BASE+75;
CMDS_CITYEVENTLIST = CMDS_BASE+76;
CMDS_OFFICIALHIRECHANGE = CMDS_BASE+77;
CMDS_CITYPROTECT = CMDS_BASE+78;
CMDS_HEROEQUIP = CMDS_BASE+79;
CMDS_HEROWASH = CMDS_BASE+80;
CMDS_HEROCOLORUP = CMDS_BASE+81;
CMDS_CITYATTR = CMDS_BASE+82;
CMDS_EQUIPWASH = CMDS_BASE+83;
CMDS_MATERIALLIST = CMDS_BASE+84;
CMDS_MATERIALWILLLIST = CMDS_BASE+85;
CMDS_STORYLIST = CMDS_BASE+86;
CMDS_STORYRANK = CMDS_BASE+87;
CMDS_STORYSTATE = CMDS_BASE+88;
CMDS_STORYRANKNUM = CMDS_BASE+89;
CMDS_STORYRANKTIME = CMDS_BASE+90;
CMDS_MAPZONECHANGE = CMDS_BASE+91;
CMDS_MAPZONEUNITLIST = CMDS_BASE+92;
CMDS_MAPZONEUNIT = CMDS_BASE+93;
CMDS_ARMYSPEEDUPDATE = CMDS_BASE+94;
CMDS_BATTLELIST = CMDS_BASE+95;
CMDS_BATTLEINFO = CMDS_BASE+96;
CMDS_MAPRESINFO = CMDS_BASE+97;
CMDS_WEATHERCHANGE = CMDS_BASE+98;
CMDS_MAIL = CMDS_BASE+99;
CMDS_MAILOPRESULT = CMDS_BASE+100;
CMDS_MAILFIGHT = CMDS_BASE+101;
CMDS_MAILVIEW = CMDS_BASE+102;
CMDS_CITYHELP = CMDS_BASE+103;
CMDS_CITYHELPLIST = CMDS_BASE+104;
CMDS_MAPCITYHELPLIST = CMDS_BASE+105;
CMDS_CITYSTATE = CMDS_BASE+106;
CMDS_CITYARMYGROUP = CMDS_BASE+107;
CMDS_CITYARMYGROUPLIST = CMDS_BASE+108;
CMDS_MAPTOWNINFO = CMDS_BASE+109;
CMDS_TOWNARMYGROUP = CMDS_BASE+110;
CMDS_TOWNARMYGROUPLIST = CMDS_BASE+111;
CMDS_SYSTALKJSON = CMDS_BASE+112;
CMDS_ROLLMSGJSON = CMDS_BASE+113;
CMDS_ROLLMSG = CMDS_BASE+114;
CMDS_TOWNOWNERASKLIST = CMDS_BASE+115;
CMDS_TOWNFIGHTLIST = CMDS_BASE+116;
CMDS_DIALOGUPDATE = CMDS_BASE+117;
CMDS_MAPTOWNEXINFO = CMDS_BASE+118;
CMDS_MAPZONETOWN = CMDS_BASE+119;
CMDS_MAPZONETOWNLIST = CMDS_BASE+120;
CMDS_MAPCENTERTOWN = CMDS_BASE+121;
CMDS_MAPCENTERTOWNLIST = CMDS_BASE+122;
CMDS_CITYWARINFO = CMDS_BASE+123;
CMDS_CITYWARLIST = CMDS_BASE+124;
CMDS_CITYWARDEL = CMDS_BASE+125;
CMDS_WORLDQUEST = CMDS_BASE+126;
CMDS_WORLDBOSS = CMDS_BASE+127;
CMDS_LOSTREBUILD = CMDS_BASE+128;
CMDS_KINGWARTOWN = CMDS_BASE+129;
CMDS_KINGWARTOWNLIST = CMDS_BASE+130;
CMDS_KINGWARACTIVITY = CMDS_BASE+131;
CMDS_KINGWARNOTIFY = CMDS_BASE+132;
CMDS_KINGWARNOTIFYLIST = CMDS_BASE+133;
CMDS_KINGWARRANKLIST = CMDS_BASE+134;
CMDS_KINGWARPK = CMDS_BASE+191;
CMDS_KINGWARPOINT = CMDS_BASE+192;
CMDS_TREASUREACTIVITY = CMDS_BASE+193;
CMDS_TREASUREHAS = CMDS_BASE+194;
CMDS_GOTOASYN = CMDS_BASE+195;
CMDS_TREASUREACTORLIST = CMDS_BASE+197;
CMDS_CHANGEAUTOBUILD = CMDS_BASE+198;
CMDS_HEROVISITINFO = CMDS_BASE+199;
CMDS_NATIONBASE = CMDS_BASE+200;
CMDS_HEROVISITAWARD = CMDS_BASE+202;
CMDS_FIGHTPLAY = CMDS_BASE+203;
CMDS_STORYSWEEPRESULT = CMDS_BASE+205;
CMDS_QUESTTALK = CMDS_BASE+206;
CMDS_RANKLIST = CMDS_BASE+209;
CMDS_FRIENDLIST = CMDS_BASE+212;
CMDS_ACTORSEARCH = CMDS_BASE+214;
CMDS_BLACKINFO = CMDS_BASE+215;
CMDS_BLACKLIST = CMDS_BASE+216;
CMDS_BLACKLISTID = CMDS_BASE+217;
CMDS_NATIONEQUIP = CMDS_BASE+218;
CMDS_SHOPLIST = CMDS_BASE+220;
CMDS_PAYSTORE = CMDS_BASE+222;
CMDS_GOODSINFO = CMDS_BASE+223;
CMDS_PAYSTOREACTIVITY = CMDS_BASE+224;
CMDS_PAYORDER = CMDS_BASE+225;
CMDS_VIPSHOP = CMDS_BASE+227;
CMDS_VIPBAG = CMDS_BASE+228;
CMDS_BUFFCHANGE = CMDS_BASE+229;
CMDS_CHANGEAUTOGUARD = CMDS_BASE+230;
CMDS_ACTIVITYLIST = CMDS_BASE+232;
CMDS_NATIONEQUIPLIST = CMDS_BASE+233;
CMDS_NATIONINFO = CMDS_BASE+234;
CMDS_NATIONTOWN = CMDS_BASE+235;
CMDS_NATIONTOWNLIST = CMDS_BASE+236;
CMDS_NATIONWARLIST = CMDS_BASE+238;
CMDS_NATIONCITYWARLIST = CMDS_BASE+240;
CMDS_NATIONQUESTLIST = CMDS_BASE+242;
CMDS_NATIONMISSIONLIST = CMDS_BASE+244;
CMDS_NATIONRANKLIST = CMDS_BASE+246;
CMDS_NATIONOFFICIALLIST = CMDS_BASE+248;
CMDS_NATIONCANDIDATELIST = CMDS_BASE+250;
CMDS_WORLDDATAOPEN = CMDS_BASE+251;
CMDS_NATIONREPLACELIST = CMDS_BASE+253;
CMDS_NATIONLOGLIST = CMDS_BASE+255;
CMDS_NATIONHEROLIST = CMDS_BASE+257;
CMDS_CITYNATIONHERO = CMDS_BASE+258;
CMDS_CITYNATIONHEROLIST = CMDS_BASE+259;
CMDS_NATIONHEROATTR = CMDS_BASE+260;
CMDS_WISHINGSHOP = CMDS_BASE+262;
CMDS_WISHINGCHANGE = CMDS_BASE+263;
CMDS_WISHINGPACK = CMDS_BASE+265;
CMDS_TIANCEQUEST = CMDS_BASE+266;
CMDS_STUDENTLIST = CMDS_BASE+268;
CMDS_TEACHERSHOPLIST = CMDS_BASE+270;
CMDS_ACTIVITY03LIST = CMDS_BASE+272;
CMDS_ACTIVITY05LIST = CMDS_BASE+274;
CMDS_ACTIVITY01LIST = CMDS_BASE+275;
CMDS_ACTIVITY04LIST = CMDS_BASE+277;

CMDC_LOGIN = CMDC_BASE+1;
CMDC_CREATE = CMDC_BASE+2;
CMDC_LIST = CMDC_BASE+3;
CMDC_ENTERGAME = CMDC_BASE+4;
CMDC_DELETE = CMDC_BASE+5;
CMDC_HEART = CMDC_BASE+6;
CMDC_GMCMD = CMDC_BASE+7;
CMDC_ASKINFO = CMDC_BASE+9;
CMDC_ENTERCITY = CMDC_BASE+10;
CMDC_CHAT = CMDC_BASE+11;
CMDC_STORYBATTLE = CMDC_BASE+12;
CMDC_WORLDMAPASK = CMDC_BASE+13;
CMDC_WORLDMAPAREAINDEX = CMDC_BASE+14;
CMDC_MAPBATTLE = CMDC_BASE+15;
CMDC_MAILASK = CMDC_BASE+16;
CMDC_MAILOP = CMDC_BASE+17;
CMDC_MAILALLDEL = CMDC_BASE+18;
CMDC_MAILSHARE = CMDC_BASE+19;
CMDC_MAILSEND = CMDC_BASE+20;
CMDC_MAILREPLY = CMDC_BASE+21;
CMDC_WORLDBOSSBATTLE = CMDC_BASE+22;
CMDC_HEROGUARDSORT = CMDC_BASE+23;
CMDC_QUESTTALKNEXT = CMDC_BASE+24;
CMDC_RANKLISTASK = CMDC_BASE+25;
CMDC_FRIENDOP = CMDC_BASE+26;

