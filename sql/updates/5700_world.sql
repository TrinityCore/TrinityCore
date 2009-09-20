
-- Sunken temple (already in world_scripts_full.sql)
UPDATE `instance_template` SET `script`='instance_sunken_temple' WHERE `map`=109;
UPDATE `gameobject_template` SET `ScriptName`='go_atalai_statue' WHERE `entry` IN (148830,148831,148832,148833,148834,148835);
DELETE FROM `areatrigger_scripts` WHERE `entry`=4016;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES (4016,'at_malfurion_stormrage');

-- Duskwood (already in world_scripts_full.sql)
DELETE FROM `areatrigger_scripts` WHERE `entry`=4017;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES (4017,'at_twilight_grove');
UPDATE `creature_template` SET `ScriptName`='boss_twilight_corrupter' WHERE `entry`=15625;

-- quest data: Long Forgotten Memories
-- TDB(???): UPDATE `quest_template` SET `method`=0 WHERE `entry`=8305;
-- quest data: A pawn on the eternal board
-- Already in world_scripts_full.sql
UPDATE `gameobject_template` SET `ScriptName`='go_crystalline_tear' WHERE `entry`=180633;
UPDATE `creature_template` SET `ScriptName`='mob_qiraj_war_spawn' WHERE `entry` IN (15414,15422,15424,15423);
UPDATE `creature_template` SET `ScriptName`='npc_anachronos_the_ancient' WHERE `entry`=15381;
UPDATE `creature_template` SET `ScriptName`='npc_anachronos_quest_trigger' WHERE `entry`=15454;

-- Already in world_script_texts.sql
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`type`,`emote`,`comment`) VALUES
   (15381,-1350000,'We must act quickly or all shall be lost!',0,1,'ANACHRONOS_SAY_1'),
   (15381,-1350001,'NOW, STAGHELM! WE GO NOW! Prepare your magic!',0,81,'ANACHRONOS_SAY_2'),
   (15381,-1350002,'Stay close...',0,1,'ANACHRONOS_SAY_3'),
   (15381,-1350003,'The sands of time will halt, but only for a moment! I will now conjure the barrier.',0,1,'ANACHRONOS_SAY_4'),
   (15381,-1350004,'FINISH THE SPELL STAGHELM! I CANNOT HOLD THE GLYPHS OF WARDING IN PLACE MUCH LONGER! CALL FORTH THE ROOTS!',0,53,'ANACHRONOS_SAY_5'),
   (15381,-1350005,'It... It is over, Lord Staghelm. We are victorious. Albeit the cost for this victory was great.',0,1,'ANACHRONOS_SAY_6'),
   (15381,-1350006,'There is but one duty that remains...',0,1,'ANACHRONOS_SAY_7'),
   (15381,-1350007,'Before I leave this place, I make one final offreing to you, Lord Staghelm. Should a time arise in which you must gain entry to this accursed fortress, use the Scepter of the Shifting Sands on the sacred gong. The magic holding the barrier together will dissipate and the horrors of Ahn''Qiraj will be unleashed upon the world once more.',0,1,'ANACHRONOS_SAY_8'),
   (15381,-1350008,'Lord Staghelm, where are you going? You would shatter our bond for the sake of pride?',0,1,'ANACHRONOS_SAY_9'),
   (15381,-1350009,'And now you know all that there is to know, mortal...',0,1,'ANACHRONOS_SAY_10'),
   (15381,-1350010,'hands the Scepter of the Shifting Sands to Fandral Staghelm.',2,1,'ANACHRONOS_EMOTE_1'),
   (15381,-1350011,'shakes his head in dissapointment.',2,274,'ANACHRONOS_EMOTE_2'),
   (15381,-1350012,'kneels down to pick up the fragments of the shattered scepter.',2,87,'ANACHRONOS_EMOTE_3'),
   (15382,-1350013,'My forces cannot overcome the Qiraji defenses. We will not be able to get close enough to place your precious barrier, dragon.',0,1,'FANDRAL_SAY_1'),
   (15382,-1350014,'It is done dragon. Lead the way...',0,1,'FANDRAL_SAY_2'),
   (15382,-1350015,'Ancient ones guide my hand... Wake from your slumber! WAKE AND SEAL THIS CURSED PLACE!',0,1,'FANDRAL_SAY_3'),
   (15382,-1350016,'After the savagery that my people have witnessed and felt, you expect me to accept another burden, dragon? Surely you are mad.',0,25,'FANDRAL_SAY_4'),
   (15382,-1350017,'I want nothing to do with Silithus, the Qiraji and least of all, any damned dragons!',0,1,'FANDRAL_SAY_5'),
   (15382,-1350018,'My son''s soul will find no comfort in this hollow victory, dragon. I will have him back.Thought it takes a millennia, I WILL have my son back!',0,254,'FANDRAL_SAY_6'),
   (15382,-1350019,'falls to one knee - exhausted.',2,16,'FANDRAL_EMOTE_1'),
   (15382,-1350020,'hurls the Scepter of the Shifting Sands into the barrier, shattering it.',2,0,'FANDRAL_EMOTE_2'),
   (15379,-1350021,'Aye, Fandral, remember these words: Let not your grief guide your faith. These thoughts you hold... dark places you go, night elf. Absolution cannot be had through misguided vengeance.',0,1,'CAELESTRASZ_SAY_1'),
   (15379,-1350022,'Do not forget the sacrifices made on this day, night elf. We have all suffered immensely at the hands of these beasts.',0,1,'CAELESTRASZ_SAY_2'),
   (15379,-1350023,'Alexstrasza grant me the resolve to drive our enemies back!',1,53,'CAELESTRASZ_YELL_1'),
   (15380,-1350024,'This distraction will give you and the young druid time enough to seal the gate. Do not falter. Now, let us see how they deal with chaotic magic.',0,1,'ARYGOS_SAY_1'),
   (15380,-1350025,'Let them feel the wrath of the Blue Flight! May Malygos protect me!',1,53,'ARYGOS_YELL_1'),
   (15380,-1350026,'nods knowingly.',2,273,'ARYGOS_EMOTE_1'),
   (15378,-1350027,'There is a way...',0,1,'MERITHRA_SAY_1'),
   (15378,-1350028,'We will push them back, Anachronos. This I vow. Uphold the end of this task. Let not your hands falter as you seal our fates behind the barrier.',0,1,'MERITHRA_SAY_2'),
   (15378,-1350029,'Succumb to the endless dream, little ones. Let it consume you!',1,53,'MERITHRA_YELL_1'),
   (15378,-1350030,'glances at her compatriots.',2,2,'MERITHRA_EMOTE_1');

-- Already in world_script_texts.sql
INSERT INTO `game_event_npc_gossip` (`guid`,`event_id`,`textid`) VALUES
   (135161,22,16000),
   (135162,22,16001);
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`prob0`,`lang0`) VALUES
   (16000,'The current situation in the front lines look like this:$B$B Iron $2000w % $B Thorium $2001w % $B Stranglekeep $2002w % $B Arthas Tears $2003w % $B Light Leather $2004w % $B Medium Leather $2005w % $B Linen Bandages $2006w % $B Silk Bandages $2007w % $B Rainbow Fin Albacore $2008w % $B Roast Raptor $2009w % $B$B Allongside with the Horde, we managed to gather: $B Copper $2020w % $B Purple Lotus $2021w % $B Thick Leather $2022w % $B Runecloth Bandage $2023w % $B Spotted Yellowtail $2024w. $B that is the current state of the effort, Aid us $N.','The current situation in the front lines look like this:$B$B Iron $2000w % $B Thorium $2001w % $B Stranglekeep $2002w % $B Arthas Tears $2003w % $B Light Leather $2004w % $B Medium Leather $2005w % $B Linen Bandages $2006w % $B Silk Bandages $2007w % $B Rainbow Fin Albacore $2008w % $B Roast Raptor $2009w % $B$B Allongside with the Horde, we managed to gather: $B Copper $2020w % $B Purple Lotus $2021w % $B Thick Leather $2022w % $B Runecloth Bandage $2023w % $B Spotted Yellowtail $2024w. $B that is the current state of the effort, Aid us $N.',100,0),
   (16001,'The current situation in the front lines look like this:$B$B Tin $2010w % $B Mithril $2011w % $B Peacebloom $2012w % $B Firebloom $2013w % $B Heavy Leather $2014w % $B Rugged Leather $2015w % $B Wool Bandages $2016w % $B Mageweave Bandages $2017w % $B Lean Wolf Steaks $2018w % $B Baked Salmon $2019w % $B$B Allongside with the Alliance, we managed to gather: $B Copper $2020w % $B Purple Lotus $2021w % $B Thick Leather $2022w % $B Runecloth Bandage $2023w % $B Spotted Yellowtail $2024w. $B that is the current state of the effort, Aid us $N.','The current situation in the front lines look like this:$B$B Tin $2010w % $B Mithril $2011w % $B Peacebloom $2012w % $B Firebloom $2013w % $B Heavy Leather $2014w % $B Rugged Leather $2015w % $B Wool Bandages $2016w % $B Mageweave Bandages $2017w % $B Lean Wolf Steaks $2018w % $B Baked Salmon $2019w % $B$B Allongside with the Alliance, we managed to gather: $B Copper $2020w % $B Purple Lotus $2021w % $B Thick Leather $2022w % $B Runecloth Bandage $2023w % $B Spotted Yellowtail $2024w. $B that is the current state of the effort, Aid us $N.',100,0);
INSERT INTO `npc_gossip` (`npc_guid`,`textid`) VALUES
   (135161,16000),
   (135162,16001);
