/* ################################################################################################
# Zalazane's Fall by Nay and Kaelima
################################################################################################ */
/* ### Variables ### */
SET @CGuid = 208901; -- (Set by TDB team - creature.guid - need X)
SET @GGuid = 151829; -- (Set by TDB team - gameobject.guid - need X)
SET @EquiEntry = 2433; -- (Set by TDB team - creature_equip_template.entry - need X)
SET @Gossip = 21257; -- (Set by TDB team - gossip_menu.entry - need 1)
SET @Event = 61; -- (Set by TDB team - game_event.entry - need 1)
-- Creature enums
SET @N_Vanira = 40184; -- Vanira
SET @N_VaniraTotem = 40187; -- Vanira's Sentry Totem
SET @N_Frog = 40176; -- Sen'jin Frog
SET @N_AtunnedFrog = 40188; -- Atunned Frog
SET @N_Voljin = 40391; -- Vol'jin
SET @N_Uruzin = 40253; -- Champion Uru'zin
SET @N_VoljinBoss = 39654; -- Vol'jin (on the island, starts fight)
SET @N_BatHandler = 40204; -- Handler Marnlek
SET @N_Bat = 40222; -- Scout Bat
SET @N_SpyFrogCredit = 40218; -- Spy Frog Credit
SET @N_TigerCredit = 40301; -- Tiger Matriarch Credit
SET @N_TigerSpirit = 40305; -- Spirit of the Tiger
SET @N_Matriarch = 40312; -- Tiger Matriarch (casts 75163 (Vicious Bite), 61184 (Pounce), 75159 (Claw))
SET @N_Zentabra = 40329; -- Zen'tabra
SET @N_DWarrior = 40392; -- Darkspear Warrior
SET @N_DScout = 40416; -- Darkspear Scout
SET @N_Citizien1 = 40256; -- Troll Citizien (1)
SET @N_Citizien2 = 40257; -- Troll Citizien (2)
SET @N_Volunteer1 = 40260; -- Troll Volunteer
SET @N_Volunteer2 = 40264; -- Troll Volunteer
SET @N_RDancer = 40356; -- Ritual Dancer
SET @N_TDanceleader = 40361; -- Troll Dance Leader
SET @N_DancePart = 40363; -- Dance Participant
SET @N_RDrummer = 40373; -- Ritual Drummer
SET @N_Omen = 40387; -- Omen Event Credit
SET @N_DAncestor = 40388; -- Darkspear Ancestor
SET @N_Voice = 40374; -- Voice of the Spirits
SET @N_Doctor = 40352; -- Witch Doctor Hez'tok
-- Gameobject enums
SET @G_BatTotem = 202833; -- Sen'jin Bat Totem
SET @G_BatStraw = 202834; -- Sen'jin Bat Roost Straw
SET @G_BatFence = 202835; -- Sen'jin Bat Roost Fence
SET @G_BatPost = 202839; -- Sen'jin Bat Roost Fence Post
SET @G_RDrum = 202879; -- Ritual Drum
SET @G_RGong = 202880; -- Ritual Gong
SET @G_RBrazier = 202881; -- Ritual Brazier
SET @G_SRDrum = 202882; -- Small Ritual Drum
SET @G_SRDrum2 = 202883; -- Small Ritual Drum 2
SET @G_Banner = 202885; -- Sen'jin Banner
SET @G_Tent = 202886; -- Sen'jin Tent
SET @G_Table = 202888; -- Sen'jin Table
SET @G_Book1 = 202889; -- Troll Book 1
SET @G_Book2 = 202890; -- Troll Book 2
SET @G_CCrate = 202891; -- Closed Weapon Crate
SET @G_OCrate = 202892; -- Open Weapon Crate
SET @G_SPennant = 202893; -- Sen'jin Pennant
-- Quest enums
SET @Q_DaPerfectSpies = 25444; -- Da Perfect Spies
SET @Q_FrogsAway = 25446; -- Frogs Away!
SET @Q_LadyOfDaTigers = 25470; -- Lady Of Da Tigers
SET @Q_DanceOfDeSpirits = 25480; -- Dance Of De Spirits
SET @Q_TrollinForVolunteers = 25461; -- Trollin' For Volunteers
SET @Q_PreparinForBattle = 25495; -- Preparin For Battle
SET @Q_ZalazanesFall = 25445; -- Zalazane's Fall
-- Spell enums
SET @S_Pickup = 74904; -- Pickup Sen'jin Frog [player -> creature]
SET @S_Pickup2 = 74905; -- Pickup Sen'jin Frog [creature -> player]
SET @S_InvsAura = 75433; -- Spawn Invisibility Aura (QZS 2)
SET @S_FrogsAway = 74977; -- Frogs Away!
SET @S_SeeSenjinFrogInvs = 75434; -- See Sen'jin Frog Invis
SET @S_SeeSpyFrogInvs =74982; -- See Spy Frog Invisibility
SET @S_Taxi_Frog = 74978; -- Echo Isles: Unlearned Spy Frog Taxi
SET @S_Taxi_Troll = 75421; -- Echo Isles: Unlearned Troll Recruit Taxi
SET @S_Taxi_Battle = 75422; -- Echo Isles: Unlearned Troll Battle Taxi
SET @S_SpyFrogInvs = 74980; -- Spy Frog Invisibility
SET @S_SmokeFlare = 74971; -- Red Flare State
SET @S_VisualSpawn = 31517; -- Bind Visual Spawn In DND
SET @S_SpyFrogState = 74917; -- Spy Frog State
SET @S_RideVehicle = 46598; -- Ride Vehicle Hardcoded
SET @S_Tiger = 75147; -- Spirit of the Tiger
SET @S_ForceTiger = 75186; -- Force Cast Spirit of the Tiger
SET @S_NatVisual = 60957; -- Cosmetic Nature Cast
SET @S_TigerAura = 75165; -- Spirit of the Tiger Aura
SET @S_TigerSeeInvs = 75180; -- Detect QZS 3
SET @S_TigerGhost = 22650; -- Ghost Visual
SET @S_BossEmotePAura =75213; -- Boss Emote & No Summon Aura
SET @S_TigerCredit = 40301; -- OCW TOTE On Quest Check (what?)
SET @S_MatriarchShroud = 75179; -- Matriarch's Shroud
SET @S_TigerQuestCredit = 75197; -- Zen'tabra Credit
SET @S_MatriarchSummonF = 75188; -- Force Cast Summon Tiger Matriarch
SET @S_MatriarchSummon = 75187; -- Summon Tiger Matriarch
SET @S_ZentabraSummon = 75181; -- Summon Zen'tabra
SET @S_ZentabraController = 75212; -- Controller Summon Zen'tabra Trigger
SET @S_ZentrabaSmoke = 36747; -- Spawn Smoke (Druid)
SET @S_ZentrabaTransform = 74931; -- [DND] Tiger Transform
SET @S_VolunterSummon1 = 75088; -- Motivate
SET @S_VolunterSummon2 = 75086; -- Motivate

-- Item enums
SET @I_VoljinDrums = 54215; -- Voljin Drums Questitem

/* ### Creatures ### */
-- Templates
UPDATE `creature_template` SET `gossip_menu_id`=11341,`faction_A`=126,`faction_H`=126,`exp`=2,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2000,`npcflag`=`npcflag`|3,`unit_flags`=`unit_flags`|33024,`equipment_id`=@EquiEntry+0,`unit_class`=2,`speed_run`=1.1428571428571,`AIName`='SmartAI' WHERE `entry`=@N_Vanira; -- Vanira
UPDATE `creature_template` SET `faction_A`=126,`faction_H`=126,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2000,`unit_flags`=`unit_flags`|256,`speed_run`=1.1428571428571 WHERE `entry`=@N_VaniraTotem; -- Vanira's Sentry Totem
UPDATE `creature_template` SET `AIName`='SmartAI',`baseattacktime`=2000,/*`npcflag`=`npcflag`|16777216,*/`speed_run`=1.1428571428571 WHERE `entry`=@N_Frog; -- Sen'jin Frog
UPDATE `creature_template` SET `faction_A`=190,`faction_H`=190,`baseattacktime`=2000,`unit_flags`=`unit_flags`|256,`speed_run`=1.1428571428571,`AIName`='SmartAI',`MovementType`=1 WHERE `entry`=@N_AtunnedFrog; -- Atunned Frog
UPDATE `creature_template` SET `gossip_menu_id`=11345,`faction_A`=126,`faction_H`=126,`exp`=2,`minlevel`=78,`maxlevel`=78,`baseattacktime`=2000,`npcflag`=`npcflag`|1,`unit_flags`=`unit_flags`|33024,`equipment_id`=191,`unit_class`=2,`speed_run`=1.1428571428571 WHERE `entry`=@N_BatHandler; -- Handler Marnlek
UPDATE `creature_template` SET `faction_A`=126,`faction_H`=126,`exp`=2,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2000,`unit_flags`=`unit_flags`|256,`speed_run`=4.2857142857143 WHERE `entry`=@N_Bat; -- Scout Bat
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|33555200,`speed_run`=1.1428571428571 WHERE `entry`=@N_SpyFrogCredit; -- Spy Frog Credit
UPDATE `creature_template` SET `spell1`=75159,`spell2`=75160,`spell3`=75161,`faction_A`=35,`faction_H`=35,`exp`=2,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2500,`unit_flags`=`unit_flags`|16777224,`unit_class`=4,`speed_walk`=2.8,`speed_run`=1.5714285714286,`vehicleid`=736,`attackpower`=1167 WHERE `entry`=@N_TigerSpirit; -- Spirit of the Tiger CHECKME: speed_run and speed_walk
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|33555200,`speed_run`=1.1428571428571,`AIName`='SmartAI' WHERE `entry`=@N_TigerCredit; -- Tiger Matriarch Credit
UPDATE `creature_template` SET `faction_A`=2102,`faction_H`=2102,`exp`=2,`minlevel`=80,`maxlevel`=80,`baseattacktime`=1625,`mindmg`=117,`maxdmg`=322,`attackpower`=143,`dmg_multiplier`=1.2,`unit_flags`=`unit_flags`|526336,`dynamicflags`=`dynamicflags`|4,`unit_class`=2,`speed_run`=1.1428571428571 WHERE `entry`=@N_Matriarch; -- Tiger Matriarch
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2000,`unit_flags`=`unit_flags`|32776,`equipment_id`=1669,`unit_class`=2,`speed_run`=1.1428571428571,`flags_extra`=`flags_extra`|2,`AIName`='SmartAI' WHERE `entry`=@N_Zentabra; -- Zen'tabra
UPDATE `creature_template` SET `faction_A`=126,`faction_H`=126,`exp`=2,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2000,`npcflag`=`npcflag`|2,`unit_flags`=`unit_flags`|33024,`equipment_id`=@EquiEntry+1,`unit_class`=2,`speed_run`=1.1428571428571 WHERE `entry`=@N_Uruzin; -- Champion Uru'zin
UPDATE `creature_template` SET `faction_A`=126,`faction_H`=126,`exp`=2,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33024,`equipment_id`=@EquiEntry+2,`speed_run`=1.1428571428571 WHERE `entry`=@N_DWarrior; -- Darkspear Warrior
UPDATE `creature_template` SET `faction_A`=126,`faction_H`=126,`exp`=2,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2000,`unit_flags`=`unit_flags`|32768,`equipment_id`=@EquiEntry+3,`speed_run`=1.1428571428571,`InhabitType`=1,`AIName`='SmartAI' WHERE `entry`=@N_DScout; -- Darkspear Scout
UPDATE `creature_template` SET `gossip_menu_id`=11391,`faction_A`=126,`faction_H`=126,`exp`=2,`minlevel`=83,`maxlevel`=83,`baseattacktime`=2000,`mindmg`=496,`maxdmg`=674,`attackpower`=783,`dmg_multiplier`=7.5,`npcflag`=`npcflag`|3,`unit_flags`=`unit_flags`|256,`equipment_id`=@EquiEntry+4,`unit_class`=2,`speed_run`=1.1428571428571 WHERE `entry`=@N_Voljin; -- Vol'jin
UPDATE `creature_template` SET `faction_A`=126,`faction_H`=126,`exp`=2,`minlevel`=70,`maxlevel`=80,`baseattacktime`=2000,`unit_flags`=`unit_flags`|256,`unit_class`=2,`speed_run`=1.1428571428571 WHERE `entry`=@N_RDancer; -- Ritual Dancer
UPDATE `creature_template` SET `faction_A`=126,`faction_H`=126,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33280,`speed_run`=1.1428571428571,`AIName`='SmartAI' WHERE `entry`=@N_Citizien1; -- Troll Citizien (1)
UPDATE `creature_template` SET `faction_A`=126,`faction_H`=126,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33280,`speed_run`=1.1428571428571,`AIName`='SmartAI' WHERE `entry`=@N_Citizien2; -- Troll Citizien (2)
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|33555200,`speed_run`=1.1428571428571 WHERE `entry`=@N_TDanceleader; -- Troll Dance Leader
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|33555200,`speed_walk`=1.6,`speed_run`=2,`InhabitType`=5,`MovementType`=1,`AIName`='SmartAI' WHERE `entry`=@N_DancePart; -- Dance Participant
UPDATE `creature_template` SET `faction_A`=126,`faction_H`=126,`exp`=2,`minlevel`=70,`maxlevel`=80,`baseattacktime`=2000,`equipment_id`=36,`unit_class`=2,`speed_run`=1.1428571428571,`AIName`='SmartAI' WHERE `entry`=@N_RDrummer; -- Ritual Drummer
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|33555200,`speed_run`=1.1428571428571 WHERE `entry`=@N_Omen; -- Omen Event Credit
UPDATE `creature_template` SET `faction_A`=126,`faction_H`=126,`exp`=2,`minlevel`=70,`maxlevel`=80,`baseattacktime`=2000,`unit_flags`=`unit_flags`|32768,`speed_run`=1.1428571428571 WHERE `entry`=@N_DAncestor; -- Darkspear Ancestor
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|0x00008308 WHERE `entry` IN (@N_Volunteer1,@N_Volunteer2); -- Troll Volunteer
UPDATE `creature_template` SET `faction_A`=126,`faction_H`=126,`exp`=2,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33536,`equipment_id`=@EquiEntry+5,`unit_class`=2,`speed_run`=1.1428571428571 WHERE `entry`=@N_Voice; -- Voice of the Spirits
UPDATE `creature_template` SET `faction_A`=126,`faction_H`=126,`exp`=2,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33536,`equipment_id`=@EquiEntry+5,`unit_class`=2,`speed_run`=1.1428571428571,`gossip_menu_id`=@Gossip,`npcflag`=`npcflag`|1,`AIName`='SmartAI' WHERE `entry`=@N_Doctor; -- Witch Doctor Hez'tok
UPDATE `creature_template` SET `npcflag`=`npcflag`|3 WHERE `entry`=@N_VoljinBoss;

-- Models
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=1 WHERE `modelid`=31719; -- Vanira
UPDATE `creature_model_info` SET `bounding_radius`=1.5,`combat_reach`=0,`gender`=2 WHERE `modelid`=31720; -- Vanira's Sentry Totem
UPDATE `creature_model_info` SET `bounding_radius`=0.25,`combat_reach`=1,`gender`=2 WHERE `modelid`=31727; -- Sen'jin Frog
UPDATE `creature_model_info` SET `bounding_radius`=0.3,`combat_reach`=1,`gender`=2 WHERE `modelid`=22469; -- Atunned Frog
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=0 WHERE `modelid`=31726; -- Handler Marnlek
UPDATE `creature_model_info` SET `bounding_radius`=0,`combat_reach`=1,`gender`=2 WHERE `modelid`=31725; -- Scout Bat
UPDATE `creature_model_info` SET `bounding_radius`=0.4,`combat_reach`=0,`gender`=2 WHERE `modelid`=19595; -- Spy Frog Credit
UPDATE `creature_model_info` SET `bounding_radius`=1.15,`combat_reach`=1,`gender`=0 WHERE `modelid`=31788; -- Spirit of the Tiger
UPDATE `creature_model_info` SET `bounding_radius`=0.125,`combat_reach`=0,`gender`=2 WHERE `modelid`=17188; -- Tiger Matriarch Credit
UPDATE `creature_model_info` SET `bounding_radius`=1.272,`combat_reach`=2,`gender`=1 WHERE `modelid`=31765; -- Tiger Matriarch
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=1 WHERE `modelid`=31734; -- Zen'tabra
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=0 WHERE `modelid`=31762; -- Champion Uru'zin
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=1 WHERE `modelid`=31841; -- Darkspear Warrior
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=1 WHERE `modelid`=31738; -- Darkspear Scout
UPDATE `creature_model_info` SET `bounding_radius`=0.3672,`combat_reach`=1,`gender`=0 WHERE `modelid`=31736; -- Vol'jin
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=0 WHERE `modelid`=9768; -- Ritual Dancer
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=1 WHERE `modelid`=2589; -- Troll Citizien (1)
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=0 WHERE `modelid`=2588; -- Troll Citizien (2)
UPDATE `creature_model_info` SET `bounding_radius`=0.125,`combat_reach`=0,`gender`=2 WHERE `modelid`=17188; -- Troll Dance Leader
UPDATE `creature_model_info` SET `bounding_radius`=0.175,`combat_reach`=0,`gender`=2 WHERE `modelid`=22769; -- Dance Participant
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=1 WHERE `modelid`=2589; -- Ritual Drummer
UPDATE `creature_model_info` SET `bounding_radius`=0.125,`combat_reach`=0,`gender`=2 WHERE `modelid`=17188; -- Omen Event Credit
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1,`gender`=1 WHERE `modelid`=4033; -- Darkspear Ancestor
UPDATE `creature_model_info` SET `bounding_radius`=0.5355,`combat_reach`=2,`gender`=0 WHERE `modelid`=31819; -- Voice of the Spirits

-- Equipments
DELETE FROM `creature_equip_template` WHERE `entry` BETWEEN @EquiEntry+0 AND @EquiEntry+5;
INSERT INTO `creature_equip_template` (`entry`,`equipentry1`,`equipentry2`,`equipentry3`) VALUES
(@EquiEntry+0,19903,13319,0), -- Vanira
(@EquiEntry+1,33982,33980,49022), -- Champion Uru'zin
(@EquiEntry+2,53924,53933,5870), -- Darkspear Warrior
(@EquiEntry+3,42873,0,5870), -- Darkspear Scout
(@EquiEntry+4,53835,0,14118), -- Vol'jin
(@EquiEntry+5,19909,0,0); -- Voice of the Spirits
-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (@N_VaniraTotem,@N_Frog,@N_AtunnedFrog,@N_BatHandler,@N_Bat,@N_SpyFrogCredit,@N_TigerSpirit,@N_TigerCredit,@N_Matriarch,@N_Zentabra,@N_Uruzin,@N_DWarrior,@N_DScout,@N_Voljin,@N_RDancer,@N_Citizien1,@N_Citizien2,@N_TDanceleader,@N_DancePart,@N_RDrummer,@N_Omen,@N_DAncestor);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@N_VaniraTotem,0,0,1,0,NULL), -- Vanira's Sentry Totem
(@N_Frog,0,65536,1,0, '75433 0'), -- Sen'jin Frog, bytes1=65536 (@S_InvsAura)
(@N_AtunnedFrog,0,0,1,0, '74917 0'), -- Atunned Frog (@S_SpyFrogState)
(@N_BatHandler,0,0,1,0,NULL), -- Handler Marnlek
(@N_Bat,0,33554432,1,0, NULL), -- Scout Bat
(@N_SpyFrogCredit,0,65536,1,0, '74980 0 74971 0'), -- Spy Frog Credit @S_SpyFrogInvs and @S_SmokeFlare
(@N_TigerSpirit,0,65536,1,0, '75180 0 22650 0'), -- Spirit of the Tiger CHECKME: remove auras? @S_TigerSeeInvs and @S_TigerGhost
(@N_TigerCredit,0,0,1,0,NULL), -- Tiger Matriarch Credit
(@N_Matriarch,0,65536,1,0, '75179 0 75179 1'), -- Tiger Matriarch @S_MatriarchShroud
(@N_Zentabra,0,0,0,0,NULL), -- Zentabra
(@N_Uruzin,0,0,2,0, '75075 0 18950 0 18950 1'), -- Champion Uru'zin
(@N_DWarrior,0,0,1,0,NULL), -- Darkspear Warrior
(@N_DScout,31725,0,1,0,NULL), -- Darkspear Scout (mounted)
(@N_Voljin,29261,0,1,0, NULL), -- Vol'jin (mounted)
(@N_RDancer,0,0,1,10, NULL), -- Ritual Dancer
(@N_Citizien1,0,0,1,0, '73940 0'), -- Troll Citizien (1)
(@N_Citizien2,0,0,1,0, '73939 0'), -- Troll Citizien (2)
(@N_TDanceleader,0,0,1,10, NULL), -- Troll Dance Leader
(@N_DancePart,0,0,1,0, '35709 0'), -- Dance Participant
(@N_RDrummer,0,0,1,173, '73940 0'), -- Ritual Drummer
(@N_Omen,0,0,1,0, NULL), -- Omen Event Credit
(@N_DAncestor,0,0,257,10, '73813 0 22650 0'); -- Darkspear Ancestor
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGuid+85 AND @CGuid+92;
INSERT INTO `creature_addon` (`guid`,`emote`,`bytes2`,`auras`) VALUES
(@CGuid+85,10,1, '75228 0'), -- Ritual Dancer
(@CGuid+86,10,1, '75229 0'), -- Ritual Dancer
(@CGuid+87,10,1, '75228 0'), -- Ritual Dancer
(@CGuid+88,10,1, '75230 0'), -- Ritual Dancer
(@CGuid+89,10,1, '75230 0'), -- Ritual Dancer
(@CGuid+90,10,1, '75230 0'), -- Ritual Dancer
(@CGuid+91,10,1, '75228 0'), -- Ritual Dancer
(@CGuid+92,10,1, '75229 0'); -- Ritual Dancer
-- Gossips
DELETE FROM `gossip_menu` WHERE `entry` IN (11341,11345,11391,@Gossip);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(11341,15796), -- Vanira
(11345,15806), -- Handler Marnlek
(11391,15865), -- Vol'jin
(@Gossip,15846); -- Witch Doctor Hez'tok

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (11345,@Gossip);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(11345,0,0, 'Vanira told me to speak to you about borrowing a bat.' ,1,1,0,0,11345*100,0,0,NULL), -- Handler Marnlek (Frogs Away quest)
(11345,1,0, 'I need to get to Razor Hill to reqruit on behalf of Vol''jin. May i borrow a bat?' ,1,1,0,0,11345*100+1,0,0,NULL), -- Handler Marnlek (Trollin' For Volunteers quest)
(11345,2,0, 'I am ready to take back the Echo Isles. Take me to the staging area!' ,1,1,0,0,11345*100+2,0,0,NULL), -- Handler Marnlek (Preparin' For Battle quest)
(@Gossip,0,0, 'Let us consult the omens.' ,1,1,0,0,0,0,0,NULL); -- Witch Doctor Hez'tok (quest Dance of De Spirits)
DELETE FROM `gossip_scripts` WHERE `id` IN (11345*100,11345*100+1,11345*100+2);
INSERT INTO `gossip_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(11345*100+0,0,15,@S_Taxi_Frog,1,0,0,0,0,0), -- Handler Marnlek (Frogs Away quest)
(11345*100+1,0,15,@S_Taxi_Troll,1,0,0,0,0,0),-- Handler Marnlek (Trollin' For Volunteers quest)
(11345*100+2,0,15,@S_Taxi_Battle,1,0,0,0,0,0);-- Handler Marnlek (Prepari' For Battle quest)

-- Spawns
DELETE FROM `creature` WHERE `id` IN (@N_Vanira,@N_VaniraTotem,@N_Frog,@N_BatHandler,@N_Bat,@N_SpyFrogCredit,@N_TigerCredit,@N_Uruzin,@N_DWarrior,@N_DScout,@N_Voljin,@N_RDancer,@N_Citizien1,@N_Citizien2,@N_Doctor);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(@CGuid+0,@N_Vanira,1,1,1,0,0,-747.175354,-5003.974,19.505209,3.769911,120,0,0,1,0,0,0), -- Vanira
(@CGuid+1,@N_VaniraTotem,1,1,1,0,0,-747.7049,-5007.78125,18.8993073,3.38593864,120,0,0,1,0,0,0), -- Vanira's Sentry Totem
(@CGuid+2,@N_Frog,1,1,1,0,0,-702.0243,-4936.85938,24.78558,0,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+3,@N_Frog,1,1,1,0,0,-706.8733,-5089.25342,10.1877956,0,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+4,@N_Frog,1,1,1,0,0,-717.1079,-5030.84961,16.7545834,0.588063061,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+5,@N_Frog,1,1,1,0,0,-721.449646,-5060.799,14.6723547,0,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+6,@N_Frog,1,1,1,0,0,-721.4549,-5041.06934,15.9652061,0,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+7,@N_Frog,1,1,1,0,0,-738.0006,-5049.516,14.9542475,5.759314,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+8,@N_Frog,1,1,1,0,0,-752.2173,-4959.93359,22.16427,1.52473652,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+9,@N_Frog,1,1,1,0,0,-754.166,-4912.5,21.3002,0.8383126,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+10,@N_Frog,1,1,1,0,0,-754.8121,-4931.80273,21.6752,1.62117982,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+11,@N_Frog,1,1,1,0,0,-764.584,-4972.916,20.9381447,1.66710317,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+12,@N_Frog,1,1,1,0,0,-790.7708,-5014.889,15.7722931,0,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+13,@N_Frog,1,1,1,0,0,-802.0174,-5037.51025,10.57736,0,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+14,@N_Frog,1,1,1,0,0,-814.3917,-5010.16064,15.0449858,4.40670633,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+15,@N_Frog,1,1,1,0,0,-817.2394,-4942.282,21.2968235,5.06702662,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+16,@N_Frog,1,1,1,0,0,-858.816,-5039.144,3.00985622,0,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+17,@N_Frog,1,1,1,0,0,-879.258667,-4998.14063,11.6243248,0,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+18,@N_Frog,1,1,1,0,0,-899.050354,-4994.48633,11.61574,0,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+19,@N_Frog,1,1,1,0,0,-924.550354,-4933.639,15.4050817,0,45,10,0,1,0,0,1), -- Sen'jin Frog
(@CGuid+20,@N_BatHandler,1,1,1,0,0,-840.052063,-4982.163,14.42927,4.86946869,120,0,0,1,0,0,0), -- Handler Marnlek
(@CGuid+21,@N_Bat,1,1,1,0,0,-833.529541,-4980.7207,17.1929779,4.29351,120,0,0,1,0,0,0), -- Scout Bat
(@CGuid+22,@N_SpyFrogCredit,1,1,1,19595,0,-1020.20831,-5152.76758,0.7509203,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+23,@N_SpyFrogCredit,1,1,1,19595,0,-1040.78821,-5585.186,3.46228218,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+24,@N_SpyFrogCredit,1,1,1,19595,0,-1049.91846,-5542.507,7.80553341,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+25,@N_SpyFrogCredit,1,1,1,19595,0,-1060.92017,-5459.61963,8.204561,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+26,@N_SpyFrogCredit,1,1,1,19595,0,-1061.52954,-5631.46338,4.56439066,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+27,@N_SpyFrogCredit,1,1,1,19595,0,-1066.36108,-5374.9165,6.87270164,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+28,@N_SpyFrogCredit,1,1,1,19595,0,-1088.9635,-5173.884,0.8336973,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+29,@N_SpyFrogCredit,1,1,1,19595,0,-1102.04858,-5435.264,10.6309662,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+30,@N_SpyFrogCredit,1,1,1,19595,0,-1123.28821,-5619.78125,5.64494038,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+31,@N_SpyFrogCredit,1,1,1,19595,0,-1127.76917,-5131.19971,2.93869424,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+32,@N_SpyFrogCredit,1,1,1,19595,0,-1129.83167,-5481.14941,7.60199165,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+33,@N_SpyFrogCredit,1,1,1,19595,0,-1148.42542,-5413.82275,9.589724,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+34,@N_SpyFrogCredit,1,1,1,19595,0,-1188.81775,-5342.51758,4.28526449,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+35,@N_SpyFrogCredit,1,1,1,19595,0,-1194.816,-5617.877,6.84516954,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+36,@N_SpyFrogCredit,1,1,1,19595,0,-1201.60413,-5379.16846,8.589357,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+37,@N_SpyFrogCredit,1,1,1,19595,0,-1240.37854,-5594.7085,8.538581,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+38,@N_SpyFrogCredit,1,1,1,19595,0,-1269.05212,-5386.241,4.37299967,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+39,@N_SpyFrogCredit,1,1,1,19595,0,-1288.60242,-5571.11475,7.43579245,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+40,@N_SpyFrogCredit,1,1,1,19595,0,-1290.526,-5122.43066,1.76108432,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+41,@N_SpyFrogCredit,1,1,1,19595,0,-1304.35938,-5169.80029,0.8500093,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+42,@N_SpyFrogCredit,1,1,1,19595,0,-1319.65625,-5477.335,5.18921232,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+43,@N_SpyFrogCredit,1,1,1,19595,0,-1321.61108,-5527.35938,4.55899572,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+44,@N_SpyFrogCredit,1,1,1,19595,0,-1423.26221,-5171.405,3.53906035,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+45,@N_SpyFrogCredit,1,1,1,19595,0,-1502.29688,-5262.67725,4.59295273,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+46,@N_SpyFrogCredit,1,1,1,19595,0,-1532.30725,-5340.738,7.00164938,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+47,@N_SpyFrogCredit,1,1,1,19595,0,-1589.217,-5340.08154,7.06946659,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+48,@N_SpyFrogCredit,1,1,1,19595,0,-1611.14233,-5275.979,7.61691332,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+49,@N_SpyFrogCredit,1,1,1,19595,0,-654.15625,-5626.69971,7.23921061,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+50,@N_SpyFrogCredit,1,1,1,19595,0,-688.0955,-5517.6875,6.0036335,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+51,@N_SpyFrogCredit,1,1,1,19595,0,-729.5972,-5655.9707,20.0036564,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+52,@N_SpyFrogCredit,1,1,1,19595,0,-732.177063,-5498.76758,5.77328968,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+53,@N_SpyFrogCredit,1,1,1,19595,0,-794.5955,-5544.462,5.39234161,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+54,@N_SpyFrogCredit,1,1,1,19595,0,-794.699646,-5350.50537,2.74348927,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+55,@N_SpyFrogCredit,1,1,1,19595,0,-805.8073,-5674.384,6.65550661,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+56,@N_SpyFrogCredit,1,1,1,19595,0,-835.071167,-5606.038,4.20461655,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+57,@N_SpyFrogCredit,1,1,1,19595,0,-853.2448,-5335.12842,2.75194836,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+58,@N_SpyFrogCredit,1,1,1,19595,0,-954.821167,-5186.238,1.09095335,0,120,0,0,1,0,0,0), -- Spy Frog Credit
(@CGuid+59,@N_TigerCredit,1,1,1,0,0,-1122.29346,-5126.54346,2.91218519,0.7679449,120,0,0,1,0,0,0), -- Tiger Matriarch Credit
(@CGuid+60,@N_Uruzin,1,1,1,0,0,-765.4323,-5018.39746,17.1423054,3.73500466,120,0,0,1,0,0,0), -- Champion Uru'zin
(@CGuid+61,@N_DWarrior,1,1,1,0,0,-732.241333,-5022.276,16.84526,3.89208412,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+62,@N_DWarrior,1,1,1,0,0,-735.364563,-5027.39941,16.4661217,2.00712872,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+63,@N_DWarrior,1,1,1,0,0,-738.178833,-4955.24854,22.872057,4.276057,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+64,@N_DWarrior,1,1,1,0,0,-738.25,-4962.1665,22.7414722,2.09439516,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+65,@N_DWarrior,1,1,1,0,0,-741.2917,-4956.875,22.88887,5.88175964,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+66,@N_DWarrior,1,1,1,0,0,-749.0781,-5000.17041,20.16327,3.89208412,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+67,@N_DWarrior,1,1,1,0,0,-757.1233,-4992.118,21.0182743,3.96189737,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+68,@N_DWarrior,1,1,1,0,0,-763.309,-5027.79541,16.8784733,0.7330383,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+69,@N_DWarrior,1,1,1,0,0,-765.3125,-5030.11133,16.3195953,0.715585,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+70,@N_DWarrior,1,1,1,0,0,-765.8906,-5025.62158,16.8368073,0.715585,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+71,@N_DWarrior,1,1,1,0,0,-767.1684,-5032.358,16.15991,0.7330383,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+72,@N_DWarrior,1,1,1,0,0,-767.9028,-5027.934,16.3112679,0.7679449,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+73,@N_DWarrior,1,1,1,0,0,-768.635437,-5023.29541,16.7641678,0.75049156,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+74,@N_DWarrior,1,1,1,0,0,-769.75,-5030.163,16.0145359,0.715585,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+75,@N_DWarrior,1,1,1,0,0,-770.6458,-5025.61475,16.2830353,0.6981317,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+76,@N_DWarrior,1,1,1,0,0,-771.302063,-5021.15967,16.708334,0.75049156,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+77,@N_DWarrior,1,1,1,0,0,-772.487854,-5027.84375,16.176178,0.5934119,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+78,@N_DWarrior,1,1,1,0,0,-773.3264,-5023.50342,16.5206375,0.7330383,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+79,@N_DWarrior,1,1,1,0,0,-773.822937,-5019.007,16.52002,0.610865235,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+80,@N_DWarrior,1,1,1,0,0,-775.158,-5025.7085,16.1457977,0.75049156,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+81,@N_DWarrior,1,1,1,0,0,-775.8455,-5021.35059,16.11615,0.558505356,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+82,@N_DWarrior,1,1,1,0,0,-777.677063,-5023.559,15.9583549,0.610865235,120,0,0,1,0,0,0), -- Darkspear Warrior
(@CGuid+83,@N_DScout,1,1,1,0,0,-860.102844,-5113.565,47.2615623,1.28633785,600,0,0,1,0,0,0), -- Darkspear Scout
(@CGuid+84,@N_Voljin,1,1,1,0,0,-755.1476,-4998.04,20.3369122,4.03171062,120,0,0,1,0,0,0), -- Vol'jin
(@CGuid+85,@N_RDancer,1,1,1,0,0,-794.6799,-4988.15674,17.72195,3.49065852,120,0,0,1,0,0,0), -- Ritual Dancer
(@CGuid+86,@N_RDancer,1,1,1,0,0,-794.896362,-4997.275,17.1909542,3.21140575,120,0,0,1,0,0,0), -- Ritual Dancer
(@CGuid+87,@N_RDancer,1,1,1,0,0,-800.975769,-4981.555,17.78231,4.276057,120,0,0,1,0,0,0), -- Ritual Dancer
(@CGuid+88,@N_RDancer,1,1,1,0,0,-801.497,-5003.56934,16.5553436,2.21656823,120,0,0,1,0,0,0), -- Ritual Dancer
(@CGuid+89,@N_RDancer,1,1,1,0,0,-810.093933,-4981.34033,17.4377289,5.148721,120,0,0,1,0,0,0), -- Ritual Dancer
(@CGuid+90,@N_RDancer,1,1,1,0,0,-810.6152,-5003.353,16.2423363,0.994837642,120,0,0,1,0,0,0), -- Ritual Dancer
(@CGuid+91,@N_RDancer,1,1,1,0,0,-816.6938,-4987.63574,16.7508545,5.846853,120,0,0,1,0,0,0), -- Ritual Dancer
(@CGuid+92,@N_RDancer,1,1,1,0,0,-816.9091,-4996.754,16.6877289,0.34906584,120,0,0,1,0,0,0), -- Ritual Dancer
(@CGuid+93,@N_Citizien1,1,1,1,0,0,246.170135,-4714.729,15.371768,5.6548667,120,0,0,1,0,0,0), -- Troll Citizien (1)
(@CGuid+94,@N_Citizien1,1,1,1,0,0,247.421875,-4675.27246,16.1996269,0.296705961,120,0,0,1,0,0,0), -- Troll Citizien (1)
(@CGuid+95,@N_Citizien1,1,1,1,0,0,248.00174,-4672.84033,16.0127563,5.41052055,120,0,0,1,0,0,0), -- Troll Citizien (1)
(@CGuid+96,@N_Citizien1,1,1,1,0,0,271.295135,-4739.4585,9.89915,5.794493,120,0,0,1,0,0,0), -- Troll Citizien (1)
(@CGuid+97,@N_Citizien1,1,1,1,0,0,273.3559,-4774.604,12.1704369,0.9599311,120,0,0,1,0,0,0), -- Troll Citizien (1)
(@CGuid+98,@N_Citizien1,1,1,1,0,0,273.432281,-4738.96338,9.832179,3.73500466,120,0,0,1,0,0,0), -- Troll Citizien (1)
(@CGuid+99,@N_Citizien1,1,1,1,0,0,343.7361,-4791.71533,11.36291,0.9599311,120,0,0,1,0,0,0), -- Troll Citizien (1)
(@CGuid+100,@N_Citizien1,1,1,1,0,0,351.678833,-4693.84033,16.5411034,2.25147462,120,0,0,1,0,0,0), -- Troll Citizien (1)
(@CGuid+101,@N_Citizien1,1,1,1,0,0,369.43576,-4690.94971,15.8566027,5.39306736,120,0,0,1,0,0,0), -- Troll Citizien (1)
(@CGuid+102,@N_Citizien1,1,1,1,0,0,375.81424,-4775.57666,12.5081263,5.75958633,120,0,0,1,0,0,0), -- Troll Citizien (1)
(@CGuid+103,@N_Citizien1,1,1,1,0,0,408.949646,-4703.797,9.698563,4.60766935,120,0,0,1,0,0,0), -- Troll Citizien (1)
(@CGuid+104,@N_Citizien1,1,1,1,0,0,411.1059,-4704.4585,9.560572,3.822271,120,0,0,1,0,0,0), -- Troll Citizien (1)
(@CGuid+105,@N_Citizien2,1,1,1,0,0,246.520828,-4717.009,15.2929316,1.53588974,120,0,0,1,0,0,0), -- Troll Citizien (2)
(@CGuid+106,@N_Citizien2,1,1,1,0,0,254.949661,-4698.413,14.71032,2.72271371,120,0,0,1,0,0,0), -- Troll Citizien (2)
(@CGuid+107,@N_Citizien2,1,1,1,0,0,266.074646,-4829.903,10.9051781,0.331612557,120,0,0,1,0,0,0), -- Troll Citizien (2)
(@CGuid+108,@N_Citizien2,1,1,1,0,0,289.449646,-4820.14258,10.6073713,0.9599311,120,0,0,1,0,0,0), -- Troll Citizien (2)
(@CGuid+109,@N_Citizien2,1,1,1,0,0,293.4236,-4798.14063,10.0895939,2.25147462,120,0,0,1,0,0,0), -- Troll Citizien (2)
(@CGuid+110,@N_Citizien2,1,1,1,0,0,333.5087,-4815.271,10.6071978,2.82743335,120,0,0,1,0,0,0), -- Troll Citizien (2)
(@CGuid+111,@N_Citizien2,1,1,1,0,0,338.1736,-4669.69434,16.5411034,4.712389,120,0,0,1,0,0,0), -- Troll Citizien (2)
(@CGuid+112,@N_Citizien2,1,1,1,0,0,343.204865,-4831.057,10.1974783,0.2443461,120,0,0,1,0,0,0), -- Troll Citizien (2)
(@CGuid+113,@N_Citizien2,1,1,1,0,0,343.3646,-4789.488,11.7296114,6.091199,120,0,0,1,0,0,0), -- Troll Citizien (2)
(@CGuid+114,@N_Citizien2,1,1,1,0,0,345.03125,-4831.41162,10.3018608,2.60054064,120,0,0,1,0,0,0), -- Troll Citizien (2)
(@CGuid+115,@N_Citizien2,1,1,1,0,0,349.482635,-4724.882,10.3245821,3.12413931,120,0,0,1,0,0,0), -- Troll Citizien (2)
(@CGuid+116,@N_Citizien2,1,1,1,0,0,375.765625,-4777.94629,12.5297422,0.7679449,120,0,0,1,0,0,0), -- Troll Citizien (2)
(@CGuid+117,@N_Doctor,1,1,1,0,0,-805.0104,-4975.75,17.75085,4.655138,120,0,0,1,0,0,0); -- Witch Doctor Hez'tok

/* ### Gameobjects ### */
-- Templates
UPDATE `gameobject_template` SET `flags`=`flags`|32 WHERE `entry`=@G_BatTotem; -- Sen'jin Bat Totem
UPDATE `gameobject_template` SET `flags`=`flags`|32 WHERE `entry`=@G_BatStraw; -- Sen'jin Bat Roost Straw
UPDATE `gameobject_template` SET `flags`=`flags`|32 WHERE `entry`=@G_BatFence; -- Sen'jin Bat Roost Fence
UPDATE `gameobject_template` SET `flags`=`flags`|32 WHERE `entry`=@G_BatPost; -- Sen'jin Bat Roost Fence Post
UPDATE `gameobject_template` SET `faction`=114 WHERE `entry`=@G_RDrum; -- Ritual Drum
UPDATE `gameobject_template` SET `faction`=114 WHERE `entry`=@G_RGong; -- Ritual Gong
UPDATE `gameobject_template` SET `flags`=`flags`|32 WHERE `entry`=@G_Banner; -- Sen'jin Banner
UPDATE `gameobject_template` SET `flags`=`flags`|32 WHERE `entry`=@G_Tent; -- Sen'jin Tent
-- Spawns
DELETE FROM `gameobject` WHERE `id` IN (@G_BatTotem,@G_BatStraw,@G_BatFence,@G_BatPost,@G_RDrum,@G_RGong,@G_RBrazier,@G_SRDrum,@G_SRDrum2,@G_Banner,@G_Tent,@G_Table,@G_Book1,@G_Book2,@G_CCrate,@G_OCrate,@G_SPennant);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GGuid+0,@G_BatTotem,1,1,1,-839.1424,-4978.337,14.5841064,-2.94959545,0,0,0,0,120,0,1), -- Sen'jin Bat Totem
(@GGuid+1,@G_BatStraw,1,1,1,-833.6285,-4980.71338,14.823576,-2.70525527,0,0,0,0,120,0,1), -- Sen'jin Bat Roost Straw
(@GGuid+2,@G_BatFence,1,1,1,-827.066,-4983.64063,15.518714,-3.07176614,0,0,0,0,120,0,1), -- Sen'jin Bat Roost Fence
(@GGuid+3,@G_BatFence,1,1,1,-829.5955,-4978.009,15.6437654,-2.44346023,0,0,0,0,120,0,1), -- Sen'jin Bat Roost Fence
(@GGuid+4,@G_BatPost,1,1,1,-831.7917,-4975.60938,15.85345,-2.40855432,0,0,0,0,120,0,1), -- Sen'jin Bat Roost Fence Post
(@GGuid+5,@G_RDrum,1,1,1,-797.4774,-4972.70166,17.8050346,-2.12930059,0,0,0,0,120,0,1), -- Ritual Drum                            
(@GGuid+6,@G_RGong,1,1,1,-789.6094,-4979.12842,18.0358353,-2.54817939,0,0,0,0,120,0,1), -- Ritual Gong
(@GGuid+7,@G_RBrazier,1,1,1,-806.4583,-4993.28125,16.5453663,0,0,0,0,0,120,0,1), -- Ritual Brazier
(@GGuid+8,@G_SRDrum,1,1,1,-799.1007,-4987.36475,17.63783,0.2792516,0,0,0,0,120,0,1), -- Small Ritual Drum
(@GGuid+9,@G_SRDrum,1,1,1,-811.529541,-4988.205,17.119791,-1.08210289,0,0,0,0,120,0,1), -- Small Ritual Drum
(@GGuid+10,@G_SRDrum2,1,1,1,-799.7882,-4986.07275,17.487505,0.2792516,0,0,0,0,120,0,1), -- Small Ritual Drum 2
(@GGuid+11,@G_SRDrum2,1,1,1,-810.487854,-4987.1665,17.1008987,-1.08210289,0,0,0,0,120,0,1), -- Small Ritual Drum 2
(@GGuid+12,@G_Banner,1,1,1,-747.2708,-4998.53467,20.1927032,-2.373644,0,0,0,0,120,0,1), -- Sen'jin Banner
(@GGuid+13,@G_Banner,1,1,1,-755.0156,-4990.882,20.33256,-2.321287,0,0,0,0,120,0,1), -- Sen'jin Banner
(@GGuid+14,@G_Banner,1,1,1,-763.5799,-4919.818,20.1778774,-0.122172989,0,0,0,0,120,0,1), -- Sen'jin Banner
(@GGuid+15,@G_Banner,1,1,1,-764.842041,-4936.15967,21.0983143,-0.209439442,0,0,0,0,120,0,1), -- Sen'jin Banner
(@GGuid+16,@G_Banner,1,1,1,-775.4427,-4895.79541,19.8775959,0.733038247,0,0,0,0,120,0,1), -- Sen'jin Banner
(@GGuid+17,@G_Banner,1,1,1,-789.1441,-4880.585,19.14895,0.7504908,0,0,0,0,120,0,1), -- Sen'jin Banner
(@GGuid+18,@G_Banner,1,1,1,-834.1094,-4873.14746,20.0067558,1.16936862,0,0,0,0,120,0,1), -- Sen'jin Banner
(@GGuid+19,@G_Banner,1,1,1,-857.8316,-4945.30566,20.62204,2.70525527,0,0,0,0,120,0,1), -- Sen'jin Banner
(@GGuid+20,@G_Banner,1,1,1,-863.6007,-4916.259,19.7371979,-2.28637886,0,0,0,0,120,0,1), -- Sen'jin Banner
(@GGuid+21,@G_Tent,1,1,1,-736.0573,-5025.12842,16.7929783,2.75761318,0,0,0,0,120,0,1), -- Sen'jin Tent
(@GGuid+22,@G_Tent,1,1,1,-738.6719,-4956.72754,22.8236065,2.75761318,0,0,0,0,120,0,1), -- Sen'jin Tent
(@GGuid+23,@G_Table,1,1,1,-736.4427,-5024.759,16.54466,0,0,0,0,0,120,0,1), -- Sen'jin Table
(@GGuid+24,@G_Table,1,1,1,-739.4375,-4957.403,22.8180714,0,0,0,0,0,120,0,1), -- Sen'jin Table
(@GGuid+25,@G_Book1,1,1,1,-735.8073,-5024.637,17.6406937,-0.6632232,0,0,0,0,120,0,1), -- Troll Book 1
(@GGuid+26,@G_Book1,1,1,1,-737.0833,-5024.98438,17.5850124,-3.10665226,0,0,0,0,120,0,1), -- Troll Book 1
(@GGuid+27,@G_Book1,1,1,1,-739.1528,-4958.62158,23.8722477,-1.23918331,0,0,0,0,120,0,1), -- Troll Book 1
(@GGuid+28,@G_Book2,1,1,1,-736.213562,-5025.762,17.5919647,-1.2566359,0,0,0,0,120,0,1), -- Troll Book 2
(@GGuid+29,@G_Book2,1,1,1,-739.194458,-4957.163,23.8564358,0.994837165,0,0,0,0,120,0,1), -- Troll Book 2
(@GGuid+30,@G_Book2,1,1,1,-740.059,-4958.033,23.8347683,-2.84488273,0,0,0,0,120,0,1), -- Troll Book 2
(@GGuid+31,@G_CCrate,1,1,1,-740.7344,-5022.94775,16.8128815,1.3264482,0,0,0,0,120,0,1), -- Closed Weapon Crate
(@GGuid+32,@G_CCrate,1,1,1,-740.8455,-5023.08154,17.3481083,1.79768872,0,0,0,0,120,0,1), -- Closed Weapon Crate
(@GGuid+33,@G_CCrate,1,1,1,-742.066,-4997.028,20.3147964,-0.0523588844,0,0,0,0,120,0,1), -- Closed Weapon Crate
(@GGuid+34,@G_CCrate,1,1,1,-742.098938,-4997.07129,20.8562927,-0.733038247,0,0,0,0,120,0,1), -- Closed Weapon Crate
(@GGuid+35,@G_CCrate,1,1,1,-743.295166,-4954.14258,22.7840157,1.3264482,0,0,0,0,120,0,1), -- Closed Weapon Crate
(@GGuid+36,@G_CCrate,1,1,1,-743.3125,-4954.191,23.3492069,2.86233544,0,0,0,0,120,0,1), -- Closed Weapon Crate
(@GGuid+37,@G_CCrate,1,1,1,-806.2153,-4925.30225,19.9984951,1.3264482,0,0,0,0,120,0,1), -- Closed Weapon Crate
(@GGuid+38,@G_CCrate,1,1,1,-806.2483,-4925.19775,19.4074268,-2.23401761,0,0,0,0,120,0,1), -- Closed Weapon Crate
(@GGuid+39,@G_CCrate,1,1,1,-819.258667,-4934.972,21.0808868,-1.04719758,0,0,0,0,120,0,1), -- Closed Weapon Crate
(@GGuid+40,@G_CCrate,1,1,1,-819.3316,-4935,20.471838,-1.58824873,0,0,0,0,120,0,1), -- Closed Weapon Crate
(@GGuid+41,@G_OCrate,1,1,1,-740.9323,-5023.299,17.89152,-2.513274,0,0,0,0,120,0,1), -- Open Weapon Crate
(@GGuid+42,@G_OCrate,1,1,1,-742.0833,-4997.009,21.4263363,-2.513274,0,0,0,0,120,0,1), -- Open Weapon Crate
(@GGuid+43,@G_OCrate,1,1,1,-743.2639,-4954.288,23.9839115,2.30383062,0,0,0,0,120,0,1), -- Open Weapon Crate
(@GGuid+44,@G_OCrate,1,1,1,-819.381958,-4934.98438,21.6449852,-0.366517574,0,0,0,0,120,0,1), -- Open Weapon Crate
(@GGuid+45,@G_SPennant,1,1,1,-729.473938,-5019.743,27.5368786,2.40855432,0,0,0,0,120,0,1), -- Sen'jin Pennant
(@GGuid+46,@G_SPennant,1,1,1,-732.1042,-4951.34033,33.59528,2.40855432,0,0,0,0,120,0,1), -- Sen'jin Pennant
(@GGuid+47,@G_SPennant,1,1,1,-735.2778,-5033.16162,27.6115456,2.40855432,0,0,0,0,120,0,1), -- Sen'jin Pennant
(@GGuid+48,@G_SPennant,1,1,1,-736.4948,-5024.741,32.8763771,2.40855432,0,0,0,0,120,0,1), -- Sen'jin Pennant
(@GGuid+49,@G_SPennant,1,1,1,-737.885437,-4964.80371,33.6575661,2.40855432,0,0,0,0,120,0,1), -- Sen'jin Pennant
(@GGuid+50,@G_SPennant,1,1,1,-739.0625,-4956.28662,39.0746231,2.40855432,0,0,0,0,120,0,1), -- Sen'jin Pennant
(@GGuid+51,@G_SPennant,1,1,1,-744.319458,-5021.384,27.2134647,2.40855432,0,0,0,0,120,0,1), -- Sen'jin Pennant
(@GGuid+52,@G_SPennant,1,1,1,-746.8889,-4953.03,33.6572571,2.40855432,0,0,0,0,120,0,1), -- Sen'jin Pennant
(@GGuid+53,@G_SPennant,1,1,1,-775.2899,-4910.69434,32.3446465,2.40855432,0,0,0,0,120,0,1), -- Sen'jin Pennant
(@GGuid+54,@G_SPennant,1,1,1,-784.7708,-4942.91846,55.81524,2.40855432,0,0,0,0,120,0,1), -- Sen'jin Pennant
(@GGuid+55,@G_SPennant,1,1,1,-802.7708,-4915.73633,29.8921642,2.40855432,0,0,0,0,120,0,1), -- Sen'jin Pennant
(@GGuid+56,@G_SPennant,1,1,1,-802.798645,-4896.53662,30.4030666,2.40855432,0,0,0,0,120,0,1), -- Sen'jin Pennant
(@GGuid+57,@G_SPennant,1,1,1,-835.0399,-4898.42725,30.9498634,2.40855432,0,0,0,0,120,0,1), -- Sen'jin Pennant
(@GGuid+58,@G_SPennant,1,1,1,-842.7656,-4939.89941,33.59177,2.40855432,0,0,0,0,120,0,1); -- Sen'jin Pennant


/* ### Quests ### */
DELETE FROM `disables` WHERE `entry` IN (@Q_DaPerfectSpies,@Q_FrogsAway,@Q_LadyOfDaTigers,@Q_DanceOfDeSpirits,@Q_TrollinForVolunteers,@Q_PreparinForBattle,@Q_ZalazanesFall); -- WTF.
-- Templates
UPDATE `quest_template` SET `PrevQuestId`=@Q_DaPerfectSpies WHERE `entry`=@Q_FrogsAway;
UPDATE `quest_template` SET `PrevQuestId`=@Q_FrogsAway WHERE `entry`=@Q_TrollinForVolunteers;
UPDATE `quest_template` SET `PrevQuestId`=@Q_TrollinForVolunteers WHERE `entry`=@Q_LadyOfDaTigers;
UPDATE `quest_template` SET `PrevQuestId`=@Q_LadyOfDaTigers WHERE `entry`=@Q_DanceOfDeSpirits;
UPDATE `quest_template` SET `PrevQuestId`=@Q_DanceOfDeSpirits WHERE `entry`=@Q_PreparinForBattle;
UPDATE `quest_template` SET `PrevQuestId`=@Q_PreparinForBattle WHERE `entry`=@Q_ZalazanesFall;
UPDATE `quest_template` SET `OfferRewardText` = 'These be enough for me purposes. Now comes de hard part.' WHERE `entry`=@Q_DaPerfectSpies;
UPDATE `quest_template` SET `OfferRewardText` = 'I''m already beginnin'' to see what de frogs are seein''. Ya done it perfectly, $N. Now Vol''jin and I will see what Zalazane be plannin''.' WHERE `entry`=@Q_FrogsAway;
UPDATE `quest_template` SET `OfferRewardText` = 'Vanira''s frog be tellin'' de truth, den? Dis tiger be a druid and an ally? We couldn''t be hopin'' for a better outcome. Dis be a good omen for de coming battle.' WHERE `entry`=@Q_LadyOfDaTigers;
UPDATE `quest_template` SET `OfferRewardText` = 'Ya found some good ones. I be trainin'' them hard and we won''t stop until we''ve driven Zalazane from our islands.' WHERE `entry`=@Q_TrollinForVolunteers;
UPDATE `quest_template` SET `OfferRewardText` = 'I will take de spirits'' advice to heart. Wit'' dem behind us and de power of de ancient loas of de Darkspear Tribe, we be ready to reclaim what''s ours!' WHERE `entry`=@Q_DanceOfDeSpirits;
UPDATE `quest_template` SET `OfferRewardText` = 'At last, everythin'' be ready. Now, we show Zalazane what happen to dose who defy de Darkspears!' WHERE `entry`=@Q_PreparinForBattle;
UPDATE `quest_template` SET `OfferRewardText` = '$N, you''d be a mighty warrior and a fierce commrade to da Darkspear trolls. De Echo Isles are OURS now and we couldn''ta done it wit''out ya.$B$BTake dis cloak. Wear it wit pride. You''d be a member of da tribe now!$B$BIn no time, da trolls will have a home again and we have you to thank for dat.' WHERE `entry`=@Q_ZalazanesFall;
-- Relations
DELETE FROM `creature_involvedrelation` WHERE `id` IN (@N_Vanira,@N_Voljin,@N_Uruzin,@N_VoljinBoss);
INSERT INTO `creature_involvedrelation` (`id`,`quest`) VALUES
(@N_Vanira,@Q_DaPerfectSpies),
(@N_Vanira,@Q_FrogsAway),
(@N_Voljin,@Q_LadyOfDaTigers),
(@N_Voljin,@Q_DanceOfDeSpirits),
(@N_Uruzin,@Q_TrollinForVolunteers),
(@N_VoljinBoss,@Q_PreparinForBattle),
(@N_Voljin,@Q_ZalazanesFall);
-- Map POI
DELETE FROM `quest_poi` WHERE `questid` IN (@Q_FrogsAway,@Q_TrollinForVolunteers,@Q_LadyOfDaTigers,@Q_DanceOfDeSpirits,@Q_PreparinForBattle,@Q_DaPerfectSpies);
INSERT INTO `quest_poi` (`questid`,`id`,`objIndex`,`mapId`,`WorldMapAreaId`,`FloorId`,`unk3`,`unk4`) VALUES
(@Q_FrogsAway,0,0,1,4,0,0,1),(@Q_FrogsAway,1,0,1,4,0,0,1),
(@Q_FrogsAway,2,0,1,4,0,0,1),(@Q_FrogsAway,3,0,1,4,0,0,1),
(@Q_FrogsAway,4,-1,1,4,0,0,1),(@Q_TrollinForVolunteers,0,0,1,4,0,0,1),
(@Q_TrollinForVolunteers,1,-1,1,4,0,0,1),(@Q_LadyOfDaTigers,0,0,1,4,0,0,1),
(@Q_LadyOfDaTigers,1,-1,1,4,0,0,1),(@Q_DanceOfDeSpirits,0,0,1,4,0,0,1),
(@Q_DanceOfDeSpirits,1,-1,1,4,0,0,1),(@Q_PreparinForBattle,0,-1,1,4,0,0,1),
(@Q_DaPerfectSpies,0,-1,1,4,0,0,1),(@Q_DaPerfectSpies,1,10,1,4,0,0,7),
(@Q_DaPerfectSpies,2,1,1,4,0,0,7);
DELETE FROM `quest_poi_points` WHERE `questid` IN (@Q_FrogsAway,@Q_TrollinForVolunteers,@Q_LadyOfDaTigers,@Q_DanceOfDeSpirits,@Q_PreparinForBattle,@Q_DaPerfectSpies);
INSERT INTO `quest_poi_points` (`questId`,`id`,`x`,`y`) VALUES
(@Q_FrogsAway,0,-1041,-5585),(@Q_FrogsAway,0,-1062,-5631),(@Q_FrogsAway,0,-1066,-5375),
(@Q_FrogsAway,0,-1189,-5343),(@Q_FrogsAway,0,-1195,-5618),(@Q_FrogsAway,0,-1269,-5386),
(@Q_FrogsAway,0,-1289,-5571),(@Q_FrogsAway,0,-1320,-5477),(@Q_FrogsAway,0,-1322,-5527),
(@Q_FrogsAway,1,-1502,-5263),(@Q_FrogsAway,1,-1532,-5341),(@Q_FrogsAway,1,-1589,-5340),
(@Q_FrogsAway,1,-1611,-5276),(@Q_FrogsAway,2,-1020,-5153),(@Q_FrogsAway,2,-1089,-5174),
(@Q_FrogsAway,2,-1128,-5131),(@Q_FrogsAway,2,-955,-5186),(@Q_FrogsAway,3,-654,-5627),
(@Q_FrogsAway,3,-688,-5518),(@Q_FrogsAway,3,-730,-5656),(@Q_FrogsAway,3,-732,-5499),
(@Q_FrogsAway,3,-795,-5544),(@Q_FrogsAway,3,-806,-5674),(@Q_FrogsAway,3,-835,-5606),
(@Q_FrogsAway,4,-747,-5004),(@Q_TrollinForVolunteers,0,246,-4715),
(@Q_TrollinForVolunteers,0,247,-4675),(@Q_TrollinForVolunteers,0,248,-4673),
(@Q_TrollinForVolunteers,0,266,-4830),(@Q_TrollinForVolunteers,0,284,-4628),
(@Q_TrollinForVolunteers,0,302,-4612),(@Q_TrollinForVolunteers,0,343,-4831),
(@Q_TrollinForVolunteers,0,345,-4831),(@Q_TrollinForVolunteers,0,376,-4778),
(@Q_TrollinForVolunteers,0,380,-4661),(@Q_TrollinForVolunteers,0,411,-4704),
(@Q_TrollinForVolunteers,1,-765,-5018),(@Q_LadyOfDaTigers,0,-1122,-5127),
(@Q_LadyOfDaTigers,1,-755,-4998),(@Q_DanceOfDeSpirits,0,-805,-4976),
(@Q_DanceOfDeSpirits,1,-755,-4998),(@Q_PreparinForBattle,0,-804,-5373),
(@Q_DaPerfectSpies,0,-747,-5004),(@Q_DaPerfectSpies,1,-1014,-4911),
(@Q_DaPerfectSpies,1,-644,-4999),(@Q_DaPerfectSpies,1,-673,-4932),
(@Q_DaPerfectSpies,1,-673,-5062),(@Q_DaPerfectSpies,1,-736,-5100),
(@Q_DaPerfectSpies,1,-740,-4873),(@Q_DaPerfectSpies,1,-808,-4831),
(@Q_DaPerfectSpies,1,-808,-5100),(@Q_DaPerfectSpies,1,-887,-5062),
(@Q_DaPerfectSpies,1,-892,-4776),(@Q_DaPerfectSpies,1,-959,-4995),
(@Q_DaPerfectSpies,1,-984,-4785),(@Q_DaPerfectSpies,2,-749,-5024);

/* # Quest fixes # */

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (@N_Frog,@N_TigerSpirit);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(@N_Frog,@S_Pickup,@Q_DaPerfectSpies,1,@Q_DaPerfectSpies,1,0,0,0),
(@N_Frog,@S_Pickup2,@Q_DaPerfectSpies,1,@Q_DaPerfectSpies,3,0,0,0),
(@N_TigerSpirit,@S_RideVehicle,0,0,0,1,0,0,0); -- Spirit of the Tiger - Ride Vehicle Hardcoded

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@N_Frog,@N_AtunnedFrog,@N_Vanira,@N_Zentabra,@N_DScout,@N_Citizien1,@N_Citizien2,@N_Doctor,@N_DancePart,@N_RDrummer) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@N_Vanira*100,@N_Zentabra*100,@N_DScout*100,@N_Doctor*100) AND `source_type`=9;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)VALUES
(@N_Frog,0,0,0,8,0,100,0,@S_Pickup,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Echo Isles: Senjin Frog - add aura'),
(@N_AtunnedFrog,0,0,0,54,0,100,0,0,0,0,0,33,@N_SpyFrogCredit,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Echo Isles: Spy Frog Killcredit'), -- FIXME: should be replaced by proper flare targeting
(@N_AtunnedFrog,0,1,0,25,0,100,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Attuned Frog: On reset set random movement'),
(@N_Vanira,0,0,0,19,0,100,0,@Q_LadyOfDaTigers,0,0,0,80,@N_Vanira*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Echo Isles: On quest accept run script'),
(@N_Vanira*100,9,0,0,0,0,100,0,0,0,0,0,11,@S_ForceTiger,0,0,0,0,0,7,0,0,0,0,0,0,0,'Echo Isles: Cast Force Tiger on player'),
(@N_Vanira*100,9,1,0,0,0,100,0,0,0,0,0,11,@S_NatVisual,0,0,0,0,0,1,0,0,0,0,0,0,0,'Echo Isles: Cast Nature Visual on self'),
(@N_Vanira*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Echo Isles: Say Text 0'),
(@N_Vanira*100,9,3,0,0,0,100,0,500,500,0,0,86,75165,0,22,0,0,0,1,0,0,0,0,0,0,0,'Echo Isles: Force Tiger cast 75165 on self'),
(@N_Zentabra,0,0,0,25,0,100,0,0,0,0,0,80,@N_Zentabra*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Call actionlist on spawn'),
(@N_Zentabra*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Set orientation to player'),
(@N_Zentabra*100,9,1,0,0,0,100,0,0,0,0,0,11,@S_ZentrabaSmoke,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Cast spawn smoke effect on self'),
(@N_Zentabra*100,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Say text 0'),
(@N_Zentabra*100,9,3,0,0,0,100,0,1500,1500,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Say text 1'),
(@N_Zentabra*100,9,4,0,0,0,100,0,5500,5500,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Say text 2'),
(@N_Zentabra*100,9,5,0,0,0,100,0,5500,5500,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Say text 3'),
(@N_Zentabra*100,9,6,0,0,0,100,0,5500,5500,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Say text 4'),
(@N_Zentabra*100,9,7,0,0,0,100,0,0,0,0,0,33,@N_TigerCredit,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Award kill credit to player'),
(@N_Zentabra*100,9,8,0,0,0,100,0,5500,5500,0,0,11,@S_ZentrabaTransform,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Cast tiger transform on self'),
(@N_Zentabra*100,9,9,0,0,0,100,0,100,100,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Set run on self'),
(@N_Zentabra*100,9,10,0,0,0,100,0,0,0,0,0,46,10,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Move self forward 10 yards'),
(@N_Zentabra*100,9,11,0,0,0,100,0,600,600,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Despawn self'),
(@N_DScout,0,0,0,25,0,100,0,0,0,0,0,53,1,@N_DScout,0,0,0,0,1,0,0,0,0,0,0,0, 'Darkspear Scout: Start waypath on spawn'),
(@N_DScout,0,1,0,40,0,100,0,1,@N_DScout,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Darkspear Scout: Set fly = 0 on waypoint 1'),
(@N_DScout,0,2,0,40,0,100,0,1,@N_DScout,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Darkspear Scout: Set run = 0 on waypoint 1'),
(@N_DScout,0,3,0,40,0,100,0,1,@N_DScout,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Darkspear Scout: Unmount on waypoint 1'),
(@N_DScout,0,4,0,40,0,100,0,6,@N_DScout,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Darkspear Scout: Pause waypoint on waypoint 6'),
(@N_DScout,0,5,0,40,0,100,0,6,@N_DScout,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0.820305, 'Darkspear Scout: Change orientation on waypoint 6'),
(@N_DScout,0,6,0,40,0,100,0,6,@N_DScout,0,0,80,@N_DScout*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Darkspear Scout: Run script on waypoint 6'),
(@N_DScout,0,7,0,40,0,100,0,9,@N_DScout,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Darkspear Scout: Despawn on waypoint 9'),
(@N_DScout*100,9,0,0,0,0,100,0,0,0,0,0,10,1,2,5,66,0,0,1,0,0,0,0,0,0,0, 'Darkspear Scout: Random emote 1,2,5,66'),
(@N_DScout*100,9,1,0,0,0,50,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Darkspear Scout: Random text'),
(@N_DScout*100,9,2,0,0,0,50,0,1000,1000,0,0,1,0,0,0,0,0,0,9,@N_Voljin,0,15,0,0,0,0, 'Vol''Jin: Reply to Darkspear Scout'),
(@N_DScout*100,9,3,0,0,0,100,0,2000,2000,0,0,10,1,2,5,66,0,0,1,0,0,0,0,0,0,0, 'Darkspear Scout: Random emote 1,2,5,66'),
(@N_DScout*100,9,4,0,0,0,100,0,6000,6000,0,0,10,1,2,5,66,0,0,1,0,0,0,0,0,0,0, 'Darkspear Scout: Random emote 1,2,5,66'),
(@N_Citizien1,0,0,0,8,0,100,0,@S_VolunterSummon1,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Echo Isles: On spellhit - force despawn'),
(@N_Citizien2,0,0,0,8,0,100,0,@S_VolunterSummon2,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Echo Isles: On spellhit - force despawn'),
(@N_Doctor, 0,0,0,62,0,0,0,@Gossip+0,0,0,0,80,@N_Doctor*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - On gossip select start script'),
(@N_Doctor*100,9,0,0,0,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Remove gossip flag'),
(@N_Doctor*100,9,1,0,0,0,100,0,1500,1500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Say text 0'),
(@N_Doctor*100,9,2,0,0,0,100,0,1000,1000,0,0,12,@N_RDrummer,1,50000,0,0,0,8,0,0,0,-812.137,-4986.7,17.3759,5.89921, 'Witch Doctor Hez''tok - Summon Ritual Drummer (1)'),
(@N_Doctor*100,9,3,0,0,0,100,0,0,0,0,0,12,@N_RDrummer,1,50000,0,0,0,8,0,0,0,-798.187,-4985.52,17.7904,4.41568, 'Witch Doctor Hez''tok - Summon Ritual Drummer (2)'),
(@N_Doctor*100,9,4,0,0,0,100,0,0,0,0,0,12,@N_RDrummer,1,50000,0,0,0,8,0,0,0,-799.888,-4975.01,17.9325,0.942478, 'Witch Doctor Hez''tok - Summon Ritual Drummer (3)'),
(@N_Doctor*100,9,5,0,0,0,100,0,3500,3500,0,0,69,0,0,0,0,0,0,8,0,0,0,-806.2,-4989.5,17.5177,0, 'Witch Doctor Hez''tok - Move to pos'),
(@N_Doctor*100,9,6,0,0,0,100,0,6500,6500,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Say text 1'),
(@N_Doctor*100,9,7,0,0,0,100,0,5500,5500,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Say text 2'),
(@N_Doctor*100,9,8,0,0,0,100,0,3500,3500,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Do emote'),
(@N_Doctor*100,9,9,0,0,0,100,0,3500,3500,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Say text 3'),
(@N_Doctor*100,9,10,0,0,0,100,0,2500,2500,0,0,5,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Do emote'),
(@N_Doctor*100,9,11,0,0,0,100,0,5000,5000,0,0,11,56745,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Cast Drink Alcohol self'),
(@N_Doctor*100,9,12,0,0,0,100,0,600,600,0,0,11,29389,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Cast Firebreathing self'),
(@N_Doctor*100,9,13,0,0,0,100,0,4000,4000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Set bytes1 kneel state'),
(@N_Doctor*100,9,14,0,0,0,100,0,1000,1000,0,0,12,@N_DancePart,1,40000,0,0,0,8,0,0,0,-805.8477,-5003.044,20.18328,5.89921, 'Witch Doctor Hez''tok - Summon Dance Participant (1)'),
(@N_Doctor*100,9,15,0,0,0,100,0,0,0,0,0,12,@N_DancePart,1,40000,0,0,0,8,0,0,0,-801.0605,-4998.501,18.59358,4.41568, 'Witch Doctor Hez''tok - Summon Dance Participant (2)'),
(@N_Doctor*100,9,16,0,0,0,100,0,0,0,0,0,12,@N_DancePart,1,40000,0,0,0,8,0,0,0,-808.2397,-4985.208,19.54311,0.942478, 'Witch Doctor Hez''tok - Summon Dance Participant (3)'),
(@N_Doctor*100,9,17,0,0,0,100,0,0,0,0,0,12,@N_DancePart,1,40000,0,0,0,8,0,0,0,-799.2618,-4994.353,19.61933,5.89921, 'Witch Doctor Hez''tok - Summon Dance Participant (4)'),
(@N_Doctor*100,9,18,0,0,0,100,0,0,0,0,0,12,@N_DancePart,1,40000,0,0,0,8,0,0,0,-797.8184,-4986.597,21.60157,4.41568, 'Witch Doctor Hez''tok - Summon Dance Participant (5)'),
(@N_Doctor*100,9,19,0,0,0,100,0,0,0,0,0,12,@N_DancePart,1,40000,0,0,0,8,0,0,0,-805.1284,-4987.553,18.79003,0.942478, 'Witch Doctor Hez''tok - Summon Dance Participant (6)'),
(@N_Doctor*100,9,20,0,0,0,100,0,0,0,0,0,12,@N_DancePart,1,40000,0,0,0,8,0,0,0,-814.1109,-5001.676,19.44409,5.89921, 'Witch Doctor Hez''tok - Summon Dance Participant (7)'),
(@N_Doctor*100,9,21,0,0,0,100,0,0,0,0,0,12,@N_DancePart,1,40000,0,0,0,8,0,0,0,-795.7561,-4993.671,21.80729,5.89921, 'Witch Doctor Hez''tok - Summon Dance Participant (8)'),
(@N_Doctor*100,9,22,0,0,0,100,0,1000,1000,0,0,12,@N_DAncestor,1,40000,0,0,0,8,0,0,0,-790.217041,-4999.733,17.171814,2.84488654, 'Witch Doctor Hez''tok - Summon Darkspear Ancestor (1)'),
(@N_Doctor*100,9,23,0,0,0,100,0,0,0,0,0,12,@N_DAncestor,1,40000,0,0,0,8,0,0,0,-792.0052,-4994.14258,17.4839725,2.70526028, 'Witch Doctor Hez''tok - Summon Darkspear Ancestor (2)'),
(@N_Doctor*100,9,24,0,0,0,100,0,0,0,0,0,12,@N_DAncestor,1,40000,0,0,0,8,0,0,0,-795.2049,-5003.078,17.716095,2.46091413, 'Witch Doctor Hez''tok - Summon Darkspear Ancestor (3)'),
(@N_Doctor*100,9,25,0,0,0,100,0,0,0,0,0,12,@N_DAncestor,1,40000,0,0,0,8,0,0,0,-799.2274,-5005.68066,16.6322536,2.11184835, 'Witch Doctor Hez''tok - Summon Darkspear Ancestor (4)'),
(@N_Doctor*100,9,26,0,0,0,100,0,0,0,0,0,12,@N_DAncestor,1,40000,0,0,0,8,0,0,0,-799.2557,-4990.76172,17.6279469,2.70527148, 'Witch Doctor Hez''tok - Summon Darkspear Ancestor (5)'),
(@N_Doctor*100,9,27,0,0,0,100,0,0,0,0,0,12,@N_DAncestor,1,40000,0,0,0,8,0,0,0,-801.422058,-4998.04346,17.0008545,2.46088934, 'Witch Doctor Hez''tok - Summon Darkspear Ancestor (6)'),
(@N_Doctor*100,9,28,0,0,0,100,0,0,0,0,0,12,@N_DAncestor,1,40000,0,0,0,8,0,0,0,-805.4358,-5002.88525,16.544487,1.727876, 'Witch Doctor Hez''tok - Summon Darkspear Ancestor (7)'),
(@N_Doctor*100,9,29,0,0,0,100,0,0,0,0,0,12,@N_DAncestor,1,40000,0,0,0,8,0,0,0,-807.135,-4997.469,17.0008545,1.15000379, 'Witch Doctor Hez''tok - Summon Darkspear Ancestor (8)'),
(@N_Doctor*100,9,30,0,0,0,100,0,0,0,0,0,12,@N_DAncestor,1,40000,0,0,0,8,0,0,0,-810.3698,-4993.825,17.1258545,0.808653831, 'Witch Doctor Hez''tok - Summon Darkspear Ancestor (9)'),
(@N_Doctor*100,9,31,0,0,0,100,0,0,0,0,0,12,@N_DAncestor,1,40000,0,0,0,8,0,0,0,-810.3889,-5004.778,16.12407,1.15191734, 'Witch Doctor Hez''tok - Summon Darkspear Ancestor (10)'),
(@N_Doctor*100,9,32,0,0,0,100,0,7000,7000,0,0,11,70663,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Cast Shadow Nova self'),
(@N_Doctor*100,9,33,0,0,0,100,0,0,0,0,0,11,31309,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Cast Spirit Particles self'),
(@N_Doctor*100,9,34,0,0,0,100,0,0,0,0,0,91,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Set bytes1 none'),
(@N_Doctor*100,9,35,0,0,0,100,0,100,100,0,0,3,@N_Voice,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Change entry to Voice of the Spirits'),
(@N_Doctor*100,9,36,0,0,0,100,0,100,100,0,0,3,0,31819,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Change model to Voice of the Spirits'),
(@N_Doctor*100,9,37,0,0,0,100,0,1000,1000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Say text 4'),
(@N_Doctor*100,9,38,0,0,0,100,0,4000,4000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Say text 5'),
(@N_Doctor*100,9,39,0,0,0,100,0,3000,3000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Do emote'),
(@N_Doctor*100,9,40,0,0,0,100,0,3500,3500,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Say text 6'),
(@N_Doctor*100,9,41,0,0,0,100,0,6000,6000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Say text 7'),
(@N_Doctor*100,9,42,0,0,0,100,0,4500,4500,0,0,5,274,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Do emote'),
(@N_Doctor*100,9,43,0,0,0,100,0,5000,5000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Say text 8'),
(@N_Doctor*100,9,44,0,0,0,100,0,4500,4500,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Do emote'),
(@N_Doctor*100,9,45,0,0,0,100,0,5500,5500,0,0,11,70663,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Cast Shadow Nova self'),
(@N_Doctor*100,9,46,0,0,0,100,0,100,100,0,0,28,31309,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Remove aura Spirit Particles'),
(@N_Doctor*100,9,47,0,0,0,100,0,0,0,0,0,3,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Change entry and model to Witch Doctor Hez''tok'),
(@N_Doctor*100,9,48,0,0,0,100,0,4000,4000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Say text 9'),
(@N_Doctor*100,9,49,0,0,0,100,0,2500,2500,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Do emote'),
(@N_Doctor*100,9,50,0,0,0,100,0,0,0,0,0,85,75319,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Cast Omen Event Credit invoker'), -- working
-- (@N_Doctor*100,9,50,0,0,0,100,0,0,0,0,0,11,75319,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Cast Omen Event Credit self'), -- how it shold be but not working
(@N_Doctor*100,9,51,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,-805.0104,-4975.75,17.75085,0, 'Witch Doctor Hez''tok - Move to pos'),
(@N_Doctor*100,9,52,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.625123, 'Witch Doctor Hez''tok - Change orientation'),
(@N_Doctor*100,9,53,0,0,0,100,0,2000,2000,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Witch Doctor Hez''tok - Enable gossip flag'),
(@N_DancePart,0,0,0,25,0,100,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dance Participant - On reset set random movement'),
(@N_DancePart,0,1,0,25,0,100,0,0,0,0,0,3,0,22769,0,0,0,0,1,0,0,0,0,0,0,0, 'Dance Participant - On reset set model'),
(@N_RDrummer,0,0,0,1,0,100,0,0,0,1000,2000,5,38,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ritual Drummer - Play emote attack 2h every 1 or 2 secs'),
(@N_RDrummer,0,1,0,1,0,100,0,0,0,5000,5000,11,75313,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ritual Drummer - Cast Bang Ritual Gong every 5 seconds'),
(@N_RDrummer,0,2,0,1,0,100,1,4000,4000,0,0,4,7294,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ritual Drummer - Play TrollDrumLoop after 4 seconds of spawn - not repeteable'),
(@N_RDrummer,0,3,0,1,0,100,0,0,0,30000,30000,4,7294,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ritual Drummer - Play Drumms sound every 30 secs');

DELETE FROM `creature_text` WHERE `entry` IN (@N_Vanira,@N_Zentabra,@N_Volunteer1,@N_Volunteer2,@N_Matriarch,@N_TigerCredit,@N_Doctor,@N_DScout,@N_Voljin);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@N_Vanira,0,0, 'O spirit of de tigers, lend $N your power and help us find de answers we seek!',0,0,100,5,0,0, 'Vanira'),
(@N_Zentabra,0,0, 'Dat be enough for now!',0,0,100,25,0,0, 'Zen''tabra'),
(@N_Zentabra,1,0, 'Don''t be lookin'' so surprised. Your shaman friend has sharp eyes, or should I say, sharp frogs.',0,0,100,1,0,0, 'Zen''tabra'),
(@N_Zentabra,2,0, 'My kind, da druids, we been layin'' low for some time now. We been waitin'' to see when an'' if Vol''jin might return.',0,0,100,11,0,0, 'Zen''tabra'),
(@N_Zentabra,3,0, 'Now dat it looks like de Darkspear be returnin'' to these isles, maybe de time has come for us to reveal ourselves.',0,0,100,1,0,0, 'Zen''tabra'),
(@N_Zentabra,4,0, 'Go back to Vol''jin an'' tell him dis: Zen''tabra stands ready to help him in de coming battle.',0,0,100,1,0,0, 'Zen''tabra'),
(@N_Volunteer1,0,0, 'Sign me up!',0,0,100,66,0,0, 'Troll Volunteer JustSpawned'),
(@N_Volunteer1,0,1, 'Anythin'' for Vol''jin!',0,0,100,0,0,0, 'Troll Volunteer JustSpawned'),
(@N_Volunteer1,0,2, 'I''d be glad to help.',0,0,100,273,0,0, 'Troll Volunteer JustSpawned'),
(@N_Volunteer1,0,3, 'Just point me at de enemy!',0,0,100,66,0,0, 'Troll Volunteer JustSpawned'),
(@N_Volunteer2,0,0, 'Sign me up!',0,0,100,66,0,0, 'Troll Volunteer JustSpawned'),
(@N_Volunteer2,0,1, 'Anythin'' for Vol''jin!',0,0,100,0,0,0, 'Troll Volunteer JustSpawned'),
(@N_Volunteer2,0,2, 'I''d be glad to help.',0,0,100,273,0,0, 'Troll Volunteer JustSpawned'),
(@N_Volunteer2,0,3, 'Just point me at de enemy!',0,0,100,66,0,0, 'Troll Volunteer JustSpawned'),
(@N_Volunteer1,1,0, 'Reportin'' for duty.',0,0,100,66,0,0, 'Troll Volunteer Quest Turn in'),
(@N_Volunteer1,1,1, 'Ready to take de fight to Zalazane.',0,0,100,1,0,0, 'Troll Volunteer Quest Turn in'),
(@N_Volunteer1,1,2, 'Ready to fight beside Vol''jin!',0,0,100,66,0,0, 'Troll Volunteer Quest Turn in'),
(@N_Volunteer1,1,3, 'New troll here!',0,0,100,0,0,0, 'Troll Volunteer Quest Turn in'),
(@N_Volunteer1,1,4, 'When does de trainin'' start?',0,0,100,6,0,0, 'Troll Volunteer Quest Turn in'),
(@N_Volunteer2,1,0, 'Reportin'' for duty.',0,0,100,66,0,0, 'Troll Volunteer Quest Turn in'),
(@N_Volunteer2,1,1, 'Ready to take de fight to Zalazane.',0,0,100,1,0,0, 'Troll Volunteer Quest Turn in'),
(@N_Volunteer2,1,2, 'Ready to fight beside Vol''jin!',0,0,100,66,0,0, 'Troll Volunteer Quest Turn in'),
(@N_Volunteer2,1,3, 'New troll here!',0,0,100,0,0,0, 'Troll Volunteer Quest Turn in'),
(@N_Volunteer2,1,4, 'When does de trainin'' start?',0,0,100,6,0,0, 'Troll Volunteer Quest Turn in'),
(@N_TigerCredit,0,0, 'The tiger matriarch appears! Prove yourself in combat!',3,0,100,0,0,0, 'Tiger Matriarch Credit'),
(@N_Doctor,0,0, 'Darkspears, we consult de spirits! Drummers, take your places!' ,0,0,100,25,0,0, 'Witch Doctor Hez''tok' ),
(@N_Doctor,1,0, 'Spirits, we be gathered here to ask for your guidance.' ,0,0,100,5,0,0, 'Witch Doctor Hez''tok' ),
(@N_Doctor,2,0, 'Our leader, Vol''jin, son of Sen''jin, issued de call to all Darkspears: reclaim de Echo Isles for our tribe.' ,0,0,100,1,0,0, 'Witch Doctor Hez''tok'),
(@N_Doctor,3,0, 'Spirits! I offer me own body to you! Speak through me! Is de time right for mighty Vol''jin''s undertaking?' ,0,0,100,5,0,0, 'Witch Doctor Hez''tok'),
(@N_Doctor,4,0, 'De ancestors hear ya, witch doctor!' ,0,0,100,1,0,0, 'Witch Doctor Hez''tok'),
(@N_Doctor,5,0, 'Know dat your plans please us, Darkspears. De son of Sen''jin walks de right path.' ,0,0,100,1,0,0, 'Witch Doctor Hez''tok'),
(@N_Doctor,6,0, 'De task in front of ya will not be easy, but ya have our blessin''.' ,0,0,100,1,0,0, 'Witch Doctor Hez''tok'),
(@N_Doctor,7,0, 'Ya gave up your home an'' ya gave up de loas of your ancestors when ya left de Echo Isles. Dey will not be pleased dat you been ignorin'' dem.' ,0,0,100,1,0,0, 'Witch Doctor Hez''tok'),
(@N_Doctor,8,0, 'Ya must make amends wit'' Bwonsamdi, de guardian of de dead, if ya hope to defeat Zalazane. It be de only way. Tell de son of Sen''jin dese things.' ,0,0,100,1,0,0, 'Witch Doctor Hez''tok'),
(@N_Doctor,9,0, 'De spirits have blessed us wit'' an answer! De Echo Isles will be ours again!' ,0,0,100,5,0,0, 'Witch Doctor Hez''tok'),
(@N_DScout,0,0, 'He got a big army, an'' he be plannin'' somethin'' down dere.' ,0,0,100,1,0,0, 'Darkspear Scout'),
(@N_DScout,0,1, 'Zalazane got most of his hexes trolls hidden under de canopy on de big island.' ,0,0,100,1,0,0, 'Darkspear Scout'),
(@N_Voljin,0,0, 'Thank ya, scout. Keep up da patrols. But for now, a rest is in order. Dismissed.' ,0,0,100,1,0,0, 'Vol''jin');

DELETE FROM `waypoints` WHERE `entry`=@N_DScout;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@N_DScout,1,-838.1788,-4989.835,14.93872, ''),
(@N_DScout,2,-829.3889,-4999.125,15.50085, ''),
(@N_DScout,3,-808.0018,-5010.587,15.36734, ''),
(@N_DScout,4,-796.1736,-5009.604,16.01879, ''),
(@N_DScout,5,-782.4566,-5002.518,17.26879, ''),
(@N_DScout,6,-758.7136,-5001.088,19.65562, 'Run script'),
(@N_DScout,7,-763.0104,-4995.054,20.06314, ''),
(@N_DScout,8,-753.5364,-4974.764,21.81314, ''),
(@N_DScout,9,-742.8715,-4961.878,22.66427, 'Despawn');

DELETE FROM `spell_area` WHERE `spell` IN (@S_SeeSenjinFrogInvs,@S_SeeSpyFrogInvs);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`) VALUES
(@S_SeeSenjinFrogInvs,393,@Q_DaPerfectSpies,1,@Q_DaPerfectSpies,0,0,2,1), -- Darkspear Strand
(@S_SeeSenjinFrogInvs,367,@Q_DaPerfectSpies,1,@Q_DaPerfectSpies,0,0,2,1), -- Sen'jin Village
(@S_SeeSenjinFrogInvs,14,@Q_DaPerfectSpies,1,@Q_DaPerfectSpies,0,0,2,1), -- Durotar
(@S_SeeSpyFrogInvs,368,@Q_FrogsAway,1,@Q_FrogsAway,0,0,2,1); -- Echo Isles

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (11345,@Gossip+0);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@S_FrogsAway;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry`=@N_TigerSpirit;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=@I_VoljinDrums;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=75319;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
(15,11345,0,0,9,@Q_FrogsAway,0,0,0, 'Echo Isles: QFrogs Away: gossip'),
(15,11345,1,0,9,@Q_TrollinForVolunteers,0,0,0, 'Echo Isles: Trollin for Volunteers: gossip'),
(15,11345,2,0,28,@Q_PreparinForBattle,0,0,0, 'Echo Isles: Preparin'' For Battle: gossip'),
(15,@Gossip+0,0,0,9,@Q_DanceOfDeSpirits,0,0,0, 'Hez''tok: Dance of De Spirits: gossip'),
(17,0,@S_FrogsAway,0,1,@S_SeeSpyFrogInvs,0,0,0, 'Echo Isles: SFrogs Away'),
(16,0,@N_TigerSpirit,0,23,367,0,0,0, 'Dismount player when not in intended zone'), -- Sen'jin Village
(16,0,@N_TigerSpirit,1,23,393,0,0,0, 'Dismount player when not in intended zone'), -- Darkspear Strand
(16,0,@N_TigerSpirit,2,23,368,0,0,0, 'Dismount player when not in intended zone'), -- Echo Isles
(18,0,@I_VoljinDrums,0,24,1,@N_Citizien1,0,63, 'Limit Voljin Drums to be used on Troll Citizen'),
(18,0,@I_VoljinDrums,1,24,1,@N_Citizien2,0,63, 'Limit Voljin Drums to be used on Troll Citizen'),
(13,0,75319,0,18,1,0,0,0, 'Omen Kill Credit - Target player AoE');

/* ### Game event ### */
DELETE FROM `game_event` WHERE `eventEntry`=@Event;
INSERT INTO `game_event` (`eventEntry`,`start_time`,`end_time`,`occurence`,`length`,`holiday`,`description`,`world_event`) VALUES
(@Event, '2010-09-07 00:00:00' , '2010-10-10 00:00:00' ,9999999,47520,0, 'Zalazane''s Fall' ,0);
DELETE FROM `game_event_creature_quest` WHERE `id` IN (@N_Vanira,@N_Voljin,@N_Uruzin,@N_VoljinBoss);
INSERT INTO `game_event_creature_quest` (`id`,`quest`,`eventEntry`) VALUES
(@N_Vanira,@Q_DaPerfectSpies,@Event),
(@N_Vanira,@Q_FrogsAway,@Event),
(@N_Vanira,@Q_LadyOfDaTigers,@Event),
(@N_Voljin,@Q_DanceOfDeSpirits,@Event),
(@N_Uruzin,@Q_TrollinForVolunteers,@Event),
(@N_Uruzin,@Q_PreparinForBattle,@Event),
(@N_VoljinBoss,@Q_ZalazanesFall,@Event);
DELETE FROM `game_event_creature` WHERE `eventEntry`=@Event;
INSERT INTO `game_event_creature` (`guid`,`eventEntry`) VALUES
(@CGuid+0,@Event),(@CGuid+1,@Event),(@CGuid+2,@Event),
(@CGuid+3,@Event),(@CGuid+4,@Event),(@CGuid+5,@Event),
(@CGuid+6,@Event),(@CGuid+7,@Event),(@CGuid+8,@Event),
(@CGuid+9,@Event),(@CGuid+10,@Event),(@CGuid+11,@Event),
(@CGuid+12,@Event),(@CGuid+13,@Event),(@CGuid+14,@Event),
(@CGuid+15,@Event),(@CGuid+16,@Event),(@CGuid+17,@Event),
(@CGuid+18,@Event),(@CGuid+19,@Event),(@CGuid+20,@Event),
(@CGuid+21,@Event),(@CGuid+22,@Event),(@CGuid+23,@Event),
(@CGuid+24,@Event),(@CGuid+25,@Event),(@CGuid+26,@Event),
(@CGuid+27,@Event),(@CGuid+28,@Event),(@CGuid+29,@Event),
(@CGuid+30,@Event),(@CGuid+31,@Event),(@CGuid+32,@Event),
(@CGuid+33,@Event),(@CGuid+34,@Event),(@CGuid+35,@Event),
(@CGuid+36,@Event),(@CGuid+37,@Event),(@CGuid+38,@Event),
(@CGuid+39,@Event),(@CGuid+40,@Event),(@CGuid+41,@Event),
(@CGuid+42,@Event),(@CGuid+43,@Event),(@CGuid+44,@Event),
(@CGuid+45,@Event),(@CGuid+46,@Event),(@CGuid+47,@Event),
(@CGuid+48,@Event),(@CGuid+49,@Event),(@CGuid+51,@Event),
(@CGuid+52,@Event),(@CGuid+53,@Event),(@CGuid+54,@Event),
(@CGuid+55,@Event),(@CGuid+56,@Event),(@CGuid+57,@Event),
(@CGuid+58,@Event),(@CGuid+59,@Event),(@CGuid+60,@Event),
(@CGuid+61,@Event),(@CGuid+62,@Event),(@CGuid+63,@Event),
(@CGuid+64,@Event),(@CGuid+65,@Event),(@CGuid+66,@Event),
(@CGuid+67,@Event),(@CGuid+68,@Event),(@CGuid+69,@Event),
(@CGuid+70,@Event),(@CGuid+71,@Event),(@CGuid+72,@Event),
(@CGuid+73,@Event),(@CGuid+74,@Event),(@CGuid+75,@Event),
(@CGuid+76,@Event),(@CGuid+77,@Event),(@CGuid+78,@Event),
(@CGuid+79,@Event),(@CGuid+80,@Event),(@CGuid+81,@Event),
(@CGuid+82,@Event),(@CGuid+83,@Event),(@CGuid+84,@Event),
(@CGuid+85,@Event),(@CGuid+86,@Event),(@CGuid+87,@Event),
(@CGuid+88,@Event),(@CGuid+89,@Event),(@CGuid+90,@Event),
(@CGuid+91,@Event),(@CGuid+92,@Event),(@CGuid+93,@Event),
(@CGuid+94,@Event),(@CGuid+95,@Event),(@CGuid+96,@Event),
(@CGuid+97,@Event),(@CGuid+98,@Event),(@CGuid+99,@Event),
(@CGuid+100,@Event),(@CGuid+101,@Event),(@CGuid+102,@Event),
(@CGuid+103,@Event),(@CGuid+104,@Event),(@CGuid+105,@Event),
(@CGuid+106,@Event),(@CGuid+107,@Event),(@CGuid+108,@Event),
(@CGuid+109,@Event),(@CGuid+110,@Event),(@CGuid+111,@Event),
(@CGuid+112,@Event),(@CGuid+113,@Event),(@CGuid+114,@Event),
(@CGuid+115,@Event),(@CGuid+116,@Event),(@CGuid+117,@Event);
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@Event;
INSERT INTO `game_event_gameobject` (`guid`,`eventEntry`) VALUES
(@GGuid+0,@Event),(@GGuid+1,@Event),(@GGuid+2,@Event),
(@GGuid+3,@Event),(@GGuid+4,@Event),(@GGuid+5,@Event),
(@GGuid+6,@Event),(@GGuid+7,@Event),(@GGuid+8,@Event),
(@GGuid+9,@Event),(@GGuid+10,@Event),(@GGuid+11,@Event),
(@GGuid+12,@Event),(@GGuid+13,@Event),(@GGuid+14,@Event),
(@GGuid+15,@Event),(@GGuid+16,@Event),(@GGuid+17,@Event),
(@GGuid+18,@Event),(@GGuid+19,@Event),(@GGuid+20,@Event),
(@GGuid+21,@Event),(@GGuid+22,@Event),(@GGuid+23,@Event),
(@GGuid+24,@Event),(@GGuid+25,@Event),(@GGuid+26,@Event),
(@GGuid+27,@Event),(@GGuid+28,@Event),(@GGuid+29,@Event),
(@GGuid+30,@Event),(@GGuid+31,@Event),(@GGuid+32,@Event),
(@GGuid+33,@Event),(@GGuid+34,@Event),(@GGuid+35,@Event),
(@GGuid+36,@Event),(@GGuid+37,@Event),(@GGuid+38,@Event),
(@GGuid+39,@Event),(@GGuid+40,@Event),(@GGuid+41,@Event),
(@GGuid+42,@Event),(@GGuid+43,@Event),(@GGuid+44,@Event),
(@GGuid+45,@Event),(@GGuid+46,@Event),(@GGuid+47,@Event),
(@GGuid+48,@Event),(@GGuid+49,@Event),(@GGuid+50,@Event),
(@GGuid+51,@Event),(@GGuid+52,@Event),(@GGuid+53,@Event),
(@GGuid+54,@Event),(@GGuid+55,@Event),(@GGuid+56,@Event),
(@GGuid+57,@Event),(@GGuid+58,@Event);
