-- Riding `trainer`s fix with new tables

-- Eversong Forest
-- Perascamin
SET @Pesca=16280;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Pesca;
DELETE FROM `trainer` WHERE id=@Pesca;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Pesca;
INSERT INTO `creature_default_trainer` VALUES (@Pesca,@Pesca);
INSERT INTO `trainer` VALUES (@Pesca,2,NULL,0);
INSERT INTO `trainer_spell` VALUES (@Pesca,33388,40000,0,0,0,0,0,20,0),(@Pesca,33391,500000,762,75,33388,0,0,40,0);

-- Orgrimmar
-- Kildar
SET @Kildar=4752;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Kildar;
DELETE FROM `trainer` WHERE id=@Kildar;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Kildar;
INSERT INTO `creature_default_trainer` VALUES (@Kildar,@Kildar);
INSERT INTO `trainer` VALUES (@Kildar,2,NULL,0);
INSERT INTO `trainer_spell` VALUES (@Kildar,33388,40000,0,0,0,0,0,20,0),(@Kildar,33391,500000,762,75,33388,0,0,40,0);

-- Revi Ramrod
SET @Revi=48513;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Revi;
DELETE FROM `trainer` WHERE id=@Revi;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Revi;
INSERT INTO `creature_default_trainer` VALUES (@Revi,@Revi);
INSERT INTO `trainer` VALUES (@Revi,2,NULL,0);
INSERT INTO `trainer_spell` VALUES (@Revi,33388,40000,0,0,0,0,0,20,0),(@Revi,33391,500000,762,75,33388,0,0,40,0);

-- Softpaws
SET @Soft=70301;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Soft;
DELETE FROM `trainer` WHERE id=@Soft;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Soft;
INSERT INTO `creature_default_trainer` VALUES (@Soft,@Soft);
INSERT INTO `trainer` VALUES (@Soft,2,NULL,0);
INSERT INTO `trainer_spell` VALUES (@Soft,33388,40000,0,0,0,0,0,20,0),(@Soft,33391,500000,762,75,33388,0,0,40,0);

-- Durotar
-- Xar'ti
SET @Xar=7953;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Xar;
DELETE FROM `trainer` WHERE id=@Xar;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Xar;
INSERT INTO `creature_default_trainer` VALUES (@Xar,@Xar);
INSERT INTO `trainer` VALUES (@Xar,2,NULL,0);
INSERT INTO `trainer_spell` VALUES (@Xar,33388,40000,0,0,0,0,0,20,0),(@Xar,33391,500000,762,75,33388,0,0,40,0);

-- Mulgore
-- Kar Stormsinger
SET @Kar=3690;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Kar;
DELETE FROM `trainer` WHERE id=@Kar;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Kar;
INSERT INTO `creature_default_trainer` VALUES (@Kar,@Kar);
INSERT INTO `trainer` VALUES (@Kar,2,NULL,0);
INSERT INTO `trainer_spell` VALUES (@Kar,33388,40000,0,0,0,0,0,20,0),(@Kar,33391,500000,762,75,33388,0,0,40,0);

-- Tirisfal Glades
-- Velma Warnam <Riding `trainer`>
SET @Velma=4773;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Velma;
DELETE FROM `trainer` WHERE id=@Velma;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Velma;
INSERT INTO `creature_default_trainer` VALUES (@Velma,@Velma);
INSERT INTO `trainer` VALUES (@Velma,2,NULL,0);
INSERT INTO `trainer_spell` VALUES (@Velma,33388,40000,0,0,0,0,0,20,0),(@Velma,33391,500000,762,75,33388,0,0,40,0);


-- Stormwind City
-- Mei Lin
SET @Mei=70296;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Mei;
DELETE FROM `trainer` WHERE id=@Mei;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Mei;
INSERT INTO `creature_default_trainer` VALUES (@Mei,@Mei);
INSERT INTO `trainer` VALUES (@Mei,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Mei,33388,40000,0,0,0,0,0,20,0),(@Mei,33391,500000,762,75,33388,0,0,40,0);

-- Darlene Stokx
SET @Darl=43693;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Darl;
DELETE FROM `trainer` WHERE id=@Darl;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Darl;
INSERT INTO `creature_default_trainer` VALUES (@Darl,@Darl);
INSERT INTO `trainer` VALUES (@Darl,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Darl,33388,40000,0,0,0,0,0,20,0),(@Darl,33391,500000,762,75,33388,0,0,40,0),
(@Darl,34090,2500000,762,150,33391,0,0,60,0),
(@Darl,34091,50000000,762,225,34090,0,0,70,0),
(@Darl,90265,50000000,762,300,34091,0,0,80,0),
(@Darl,90267,2500000,762,225,34090,0,0,60,0),
(@Darl,54197,500000,762,225,34090,0,0,68,0);

-- Dun Morogh
-- Ultham Ironhorn
SET @Ulth=4772;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Ulth;
DELETE FROM `trainer` WHERE id=@Ulth;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Ulth;
INSERT INTO `creature_default_trainer` VALUES (@Ulth,@Ulth);
INSERT INTO `trainer` VALUES (@Ulth,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Ulth,33388,40000,0,0,0,0,0,20,0),(@Ulth,33391,500000,762,75,33388,0,0,40,0);

-- Binjy Featherwhistle
SET @Binjy=7954;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Binjy;
DELETE FROM `trainer` WHERE id=@Binjy;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Binjy;
INSERT INTO `creature_default_trainer` VALUES (@Binjy,@Binjy);
INSERT INTO `trainer` VALUES (@Binjy,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Binjy,33388,40000,0,0,0,0,0,20,0),(@Binjy,33391,500000,762,75,33388,0,0,40,0);

-- Dustwallow Marsh
-- Sansha MacVince
SET @Mac=53407;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Mac;
DELETE FROM `trainer` WHERE id=@Mac;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Mac;
INSERT INTO `creature_default_trainer` VALUES (@Mac,@Mac);
INSERT INTO `trainer` VALUES (@Mac,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Mac,33388,40000,0,0,0,0,0,20,0),(@Mac,33391,500000,762,75,33388,0,0,40,0);

-- Darnassus
-- Jartsam
SET @Jar=4753;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Jar;
DELETE FROM `trainer` WHERE id=@Jar;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Jar;
INSERT INTO `creature_default_trainer` VALUES (@Jar,@Jar);
INSERT INTO `trainer` VALUES (@Jar,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Jar,33388,40000,0,0,0,0,0,20,0),(@Jar,33391,500000,762,75,33388,0,0,40,0);

-- The Exodar
-- Aalun
SET @Aalun=20914;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Aalun;
DELETE FROM `trainer` WHERE id=@Aalun;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Aalun;
INSERT INTO `creature_default_trainer` VALUES (@Aalun,@Aalun);
INSERT INTO `trainer` VALUES (@Aalun,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Aalun,33388,40000,0,0,0,0,0,20,0),(@Aalun,33391,500000,762,75,33388,0,0,40,0);

-- Elwynn Forest
-- Randal Hunter
SET @Randal=4732;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Randal;
DELETE FROM `trainer` WHERE id=@Randal;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Randal;
INSERT INTO `creature_default_trainer` VALUES (@Randal,@Randal);
INSERT INTO `trainer` VALUES (@Randal,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Randal,33388,40000,0,0,0,0,0,20,0),(@Randal,33391,500000,762,75,33388,0,0,40,0);


-- Flying `trainer`

-- Maelstorm
-- Vale of Eternal Blossoms
-- Cloudrunner Leng
SET @Leng=60166;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Leng;
DELETE FROM `trainer` WHERE id=@Leng;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Leng;
INSERT INTO `creature_default_trainer` VALUES (@Leng,@Leng);
INSERT INTO `trainer` VALUES (@Leng,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Leng,33388,40000,0,0,0,0,0,20,0),(@Leng,33391,500000,762,75,33388,0,0,40,0),
(@Leng,34090,2500000,762,150,33391,0,0,60,0),
(@Leng,34091,50000000,762,225,34090,0,0,70,0),
(@Leng,90265,50000000,762,300,34091,0,0,80,0),
(@Leng,90267,2500000,762,225,34090,0,0,60,0),
(@Leng,54197,500000,762,225,34090,0,0,68,0),
(@Leng,115913,25000000,762,225,34090,0,0,85,0);

-- Skydancer Shun <Flying `trainer`>
SET @Shun=60167;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Shun;
DELETE FROM `trainer` WHERE id=@Shun;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Shun;
INSERT INTO `creature_default_trainer` VALUES (@Shun,@Shun);
INSERT INTO `trainer` VALUES (@Shun,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Shun,33388,40000,0,0,0,0,0,20,0),(@Shun,33391,500000,762,75,33388,0,0,40,0),
(@Shun,34090,2500000,762,150,33391,0,0,60,0),
(@Shun,34091,50000000,762,225,34090,0,0,70,0),
(@Shun,90265,50000000,762,300,34091,0,0,80,0),
(@Shun,90267,2500000,762,225,34090,0,0,60,0),
(@Shun,54197,500000,762,225,34090,0,0,68,0),
(@Shun,115913,25000000,762,225,34090,0,0,85,0);

-- Norhrend
-- Dalaran
-- Hira Snowdawn 
SET @Hira=31238;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Hira;
DELETE FROM `trainer` WHERE id=@Hira;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Hira;
DELETE FROM `gossip_menu_option_trainer` WHERE `MenuID`=10723 AND `trainerId`=@Hira;
INSERT INTO `creature_default_trainer` VALUES (@Hira,@Hira);
INSERT INTO `trainer` VALUES (@Hira,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Hira,33388,40000,0,0,0,0,0,20,0),(@Hira,33391,500000,762,75,33388,0,0,40,0),
(@Hira,34090,2500000,762,150,33391,0,0,60,0),
(@Hira,34091,50000000,762,225,34090,0,0,70,0),
(@Hira,90265,50000000,762,300,34091,0,0,80,0),
(@Hira,90267,2500000,762,225,34090,0,0,60,0),
(@Hira,54197,500000,762,225,34090,0,0,68,0);
INSERT INTO `gossip_menu_option_trainer` VALUES
(10723,0,@Hira);

-- Storm Peaks
-- Roxi Ramrocket
SET @Roxi=31247;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Roxi;
DELETE FROM `trainer` WHERE id=@Roxi;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Roxi;
DELETE FROM `gossip_menu_option_trainer` WHERE `MenuID`=10210 AND `trainerId`=@Roxi;
DELETE FROM gossip_menu_option WHERE `MenuID`=10210 AND optionType=3;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10210 AND `SourceEntry`=1;
INSERT INTO `creature_default_trainer` VALUES (@Roxi,@Roxi);
INSERT INTO `trainer` VALUES (@Roxi,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Roxi,33388,40000,0,0,0,0,0,20,0),(@Roxi,33391,500000,762,75,33388,0,0,40,0),
(@Roxi,34090,2500000,762,150,33391,0,0,60,0),(@Roxi,34091,50000000,762,225,34090,0,0,70,0),
(@Roxi,90265,50000000,762,300,34091,0,0,80,0),(@Roxi,90267,2500000,762,225,34090,0,0,60,0),
(@Roxi,54197,500000,762,225,34090,0,0,68,0);
INSERT INTO `gossip_menu_option_trainer` VALUES
(10210,0,@Roxi);
INSERT INTO gossip_menu_option VALUES
(10210,1,1,NULL,3370,3,128,0);
INSERT INTO `conditions`  VALUES
(15,10210,1,0,0,25,0,60866,0,0,0,0,0,'',''),(15,10210,1,0,1,25,0,60867,0,0,0,0,0,'','');
UPDATE `creature_template` SET `ScriptName`='' /*npc_roxi_ramrocket*/ WHERE `entry`=31247;

-- Borean Tundra
-- Wind Rider Sabamba 
SET @Sab=35135;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Sab;
DELETE FROM `trainer` WHERE id=@Sab;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Sab;
INSERT INTO `creature_default_trainer` VALUES (@Sab,@Sab);
INSERT INTO `trainer` VALUES (@Sab,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Sab,33388,40000,0,0,0,0,0,20,0),(@Sab,33391,500000,762,75,33388,0,0,40,0),
(@Sab,34090,2500000,762,150,33391,0,0,60,0),
(@Sab,34091,50000000,762,225,34090,0,0,70,0),
(@Sab,90265,50000000,762,300,34091,0,0,80,0),
(@Sab,90267,2500000,762,225,34090,0,0,60,0),
(@Sab,54197,500000,762,225,34090,0,0,68,0);

-- Maigra Keenfeather
SET @Maigra=35133;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Maigra;
DELETE FROM `trainer` WHERE id=@Maigra;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Maigra;
INSERT INTO `creature_default_trainer` VALUES (@Maigra,@Maigra);
INSERT INTO `trainer` VALUES (@Maigra,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Maigra,33388,40000,0,0,0,0,0,20,0),(@Maigra,33391,500000,762,75,33388,0,0,40,0),
(@Maigra,34090,2500000,762,150,33391,0,0,60,0),
(@Maigra,34091,50000000,762,225,34090,0,0,70,0),
(@Maigra,90265,50000000,762,300,34091,0,0,80,0),
(@Maigra,90267,2500000,762,225,34090,0,0,60,0),
(@Maigra,54197,500000,762,225,34090,0,0,68,0);

-- Stormwind City
-- Bralla Cloudwing
SET @Bralla=43769;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Bralla;
DELETE FROM `trainer` WHERE id=@Bralla;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Bralla;
INSERT INTO `creature_default_trainer` VALUES (@Bralla,@Bralla);
INSERT INTO `trainer` VALUES (@Bralla,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Bralla,33388,40000,0,0,0,0,0,20,0),(@Bralla,33391,500000,762,75,33388,0,0,40,0),
(@Bralla,34090,2500000,762,150,33391,0,0,60,0),
(@Bralla,34091,50000000,762,225,34090,0,0,70,0),
(@Bralla,90265,50000000,762,300,34091,0,0,80,0),
(@Bralla,90267,2500000,762,225,34090,0,0,60,0),
(@Bralla,54197,500000,762,225,34090,0,0,68,0);

-- Orgrimmar
-- Maztha
SET @Maz=44919;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Maz;
DELETE FROM `trainer` WHERE id=@Maz;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Maz;
INSERT INTO `creature_default_trainer` VALUES (@Maz,@Maz);
INSERT INTO `trainer` VALUES (@Maz,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Maz,33388,40000,0,0,0,0,0,20,0),(@Maz,33391,500000,762,75,33388,0,0,40,0),
(@Maz,34090,2500000,762,150,33391,0,0,60,0),
(@Maz,34091,50000000,762,225,34090,0,0,70,0),
(@Maz,90265,50000000,762,300,34091,0,0,80,0),
(@Maz,90267,2500000,762,225,34090,0,0,60,0),
(@Maz,54197,500000,762,225,34090,0,0,68,0);

-- Sholazar Basin
-- Pilot Vic
SET @Vic=28746;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Vic;
DELETE FROM `trainer` WHERE id=@Vic;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Vic;
DELETE FROM `gossip_menu_option_trainer` WHERE `MenuID`=9750;
INSERT INTO `creature_default_trainer` VALUES (@Vic,@Vic);
INSERT INTO `trainer` VALUES (@Vic,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Vic,33388,40000,0,0,0,0,0,20,0),(@Vic,33391,500000,762,75,33388,0,0,40,0),
(@Vic,34090,2500000,762,150,33391,0,0,60,0),
(@Vic,34091,50000000,762,225,34090,0,0,70,0),
(@Vic,90265,50000000,762,300,34091,0,0,80,0),
(@Vic,90267,2500000,762,225,34090,0,0,60,0),
(@Vic,54197,500000,762,225,34090,0,0,68,0);
INSERT INTO `gossip_menu_option_trainer` VALUES
(9750,0,@Vic);


-- Hellfire Peninsula
-- Wind Rider Jahubo
SET @Jahubo=35093;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Jahubo;
DELETE FROM `trainer` WHERE id=@Jahubo;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Jahubo;
INSERT INTO `creature_default_trainer` VALUES (@Jahubo,@Jahubo);
INSERT INTO `trainer` VALUES (@Jahubo,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Jahubo,33388,40000,0,0,0,0,0,20,0),(@Jahubo,33391,500000,762,75,33388,0,0,40,0),
(@Jahubo,34090,2500000,762,150,33391,0,0,60,0),
(@Jahubo,34091,50000000,762,225,34090,0,0,70,0),
(@Jahubo,90265,50000000,762,300,34091,0,0,80,0),
(@Jahubo,90267,2500000,762,225,34090,0,0,60,0),
(@Jahubo,54197,500000,762,225,34090,0,0,68,0);

-- Hargen Bronzewing
SET @Hargen=35100;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Hargen;
DELETE FROM `trainer` WHERE id=@Hargen;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Hargen;
INSERT INTO `creature_default_trainer` VALUES (@Hargen,@Hargen);
INSERT INTO `trainer` VALUES (@Hargen,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Hargen,33388,40000,0,0,0,0,0,20,0),(@Hargen,33391,500000,762,75,33388,0,0,40,0),
(@Hargen,34090,2500000,762,150,33391,0,0,60,0),
(@Hargen,34091,50000000,762,225,34090,0,0,70,0),
(@Hargen,90265,50000000,762,300,34091,0,0,80,0),
(@Hargen,90267,2500000,762,225,34090,0,0,60,0),
(@Hargen,54197,500000,762,225,34090,0,0,68,0);

-- Shadowmoon Valley
-- Ilsa Blusterbrew
SET @Ilsa=20511;
DELETE FROM `creature_default_trainer` WHERE `CreatureID`=@Ilsa;
DELETE FROM `trainer` WHERE id=@Ilsa;
DELETE FROM `trainer_spell` WHERE `trainerId`=@Ilsa;
INSERT INTO `creature_default_trainer` VALUES (@Ilsa,@Ilsa);
INSERT INTO `trainer` VALUES (@Ilsa,2,NULL,0);
INSERT INTO `trainer_spell` VALUES 
(@Ilsa,33388,40000,0,0,0,0,0,20,0),(@Ilsa,33391,500000,762,75,33388,0,0,40,0),
(@Ilsa,34090,2500000,762,150,33391,0,0,60,0),
(@Ilsa,34091,50000000,762,225,34090,0,0,70,0),
(@Ilsa,90265,50000000,762,300,34091,0,0,80,0),
(@Ilsa,90267,2500000,762,225,34090,0,0,60,0),
(@Ilsa,54197,500000,762,225,34090,0,0,68,0);