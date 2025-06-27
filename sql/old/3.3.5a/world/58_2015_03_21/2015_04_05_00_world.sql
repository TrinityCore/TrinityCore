        SET @OGUID       := 16926;

        -- Creatures :
        SET @MOGRAINE       := 20345;
        SET @ISILLIEN      := 20346;
        SET @ABBENDIS      := 20347;
        SET @FAIRBANKS      := 20348;
        SET @TIRION      := 20349;
        SET @DOAN      := 20352;
        SET @TARGET       := 20391; -- for spells
        -- DB Guids :
        SET @MGUID       := 83685;
        SET @FGUID      := 83686;
        SET @DGUID      := 83689;
        SET @TGUID      := 83690;
        SET @IGUID      := 83691;
        SET @AGUID      := 83692;
        -- Event
        SET @TRIGG       := 4498;
        -- Default difference between events
        SET @DELAY      := 3000000;
        -- Objects
        SET @CHAIR      := 184305;
        SET @DARK      := 184306;
        SET @LIGHT      := 184307;
        SET @CHEST      := 184308;
        -- Positions
        SET @CHESTX      := 1816.698;
        SET @CHESTY      := 1031.316;
        SET @CHESTZ      := 11.84751;
        -- Spells
        SET @TBTL       := 35172;
        SET @JUDGE      := 35170;
        SET @SHOCK      := 35160;
        SET @SMITE      := 35155;
        SET @HEALS      := 35162;

        DELETE FROM `gameobject` WHERE `id` BETWEEN 22882 AND 22887 AND `map`=560;
        INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
        (@OGUID+0, 22882, 560, 3, 1, 1823.365, 1029.282, 11.64124, 1.439896, 0, 0, 0.7071069, 0.7071066, 7200, 255, 1),
        (@OGUID+1, 22883, 560, 3, 1, 1824.24, 1031.343, 11.64124, 0.5061446, 0, 0, 0.7071069, 0.7071066, 7200, 255, 1),
        (@OGUID+2, 22884, 560, 3, 1, 1822.9, 1032.183, 11.64124, 3.141593, 0, 0, 0.7071069, 0.7071066, 7200, 255, 1),
        (@OGUID+3, 22885, 560, 3, 1, 1813.827, 999.6839, 12.13165, 0.1047193, 0, 0, 0.7071069, 0.7071066, 7200, 255, 1),
        (@OGUID+4, 22886, 560, 3, 1, 1822.891, 1030.719, 11.64124, 4.232424, 0, 0, 0.7071069, 0.7071066, 7200, 255, 1),
        (@OGUID+5, 22887, 560, 3, 1, 1812.618, 999.1037, 12.13165, 1.509709, 0, 0, 0.7071069, 0.7071066, 7200, 255, 1);

        DELETE FROM `conditions` WHERE `SourceEntry` IN (@SMITE,@SHOCK,@JUDGE,@HEALS);
        INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
        (13,1,@SMITE,0,0,31,0,3,@TARGET,0,0,0,'','Spell casts only on Creature 20391'),
        (13,1,@SHOCK,0,0,31,0,3,@TARGET,0,0,0,'','Spell casts only on Creature 20391'),
        (13,1,@JUDGE,0,0,31,0,3,@TARGET,0,0,0,'','Spell casts only on Creature 20391'),
        (13,1,@HEALS,0,0,31,0,3,@TARGET,0,0,0,'','Spell casts only on Creature 20391');

        DELETE FROM `creature_text` WHERE `entry` IN (@MOGRAINE,@ISILLIEN,@ABBENDIS,@FAIRBANKS,@TIRION,@DOAN);
        INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `BroadcastTextId`, `comment`) VALUES
        -- Commander Mograine
        (@MOGRAINE, 0 , 0, 'Keep your voices down. There are strangers about...' ,12 ,0,100,1,18084, ' Mograine - 1'),
        (@MOGRAINE, 1 , 0, 'Brothers and sisters, I have called you here today to discuss the fate of Lordaeron.' ,12 ,0,100,1,18085, ' Mograine - 2'),
        (@MOGRAINE, 2 , 0, 'I hear things... Things that should not be.' ,12 ,0,100,1,18087, ' Mograine - 3'),
        (@MOGRAINE, 3 , 0, 'The dead rise... Undead, from the frozen northlands. Whole cities have gone missing. I...' ,12 ,0,100,1,18088, ' Mograine - 4'),
        (@MOGRAINE, 4 , 0, 'I have heard that Northrend is lost...' ,12 ,0,100,274,18089, ' Mograine - 5'),
        (@MOGRAINE, 5 , 0, 'We must stand at the ready. I have faced undead before. They are ruthless killing machines, devoid of any emotion or compassion.' ,12 ,0,100,1,18091, ' Mograine - 6'),
        (@MOGRAINE, 6 , 0, 'Propose? I propose that we prepare. That we prepare our loved ones, family and friends for the possibility of an undead holocaust.' ,12 ,0,100,6,18095, ' Mograine - 7'),
        (@MOGRAINE, 7 , 0, 'And there is this...' ,12 ,0,100,6,18096, ' Mograine - 8'),
        (@MOGRAINE, 8 , 0, 'I have had this object in my possession for 10 years. Since Blackrock Spire...' ,12 ,0,100,1,18099, ' Mograine - 9'),
        (@MOGRAINE, 9 , 0, 'I wrested it free from the remains of an orc lieutenant - a dark caster... It is from their homeworld.' ,12 ,0,100,1,18100, ' Mograine - 10'),
        (@MOGRAINE, 10 , 0, 'Do not get too close. I laid a hand upon it once... Only once and never again. The memories of that day still linger.' ,12 ,0,100,1,18101, ' Mograine - 11'),
        (@MOGRAINE, 11 , 0, 'I surmise that this object is the living embodiment of shadows... darkness... It is a manifestation. It is a void.' ,12 ,0,100,1,18103, ' Mograine - 12'),
        (@MOGRAINE, 12 , 0, 'No, old friend, it is very relevant.' ,12 ,0,100,1,18107, ' Mograine - 13'),
        (@MOGRAINE, 13 , 0, 'Let me ask you this, brothers and sisters: Can good exist without evil? Can there be light without dark?' ,12 ,0,100,1,18108, ' Mograine - 14'),
        (@MOGRAINE, 14 , 0, 'And if that answer is no, then could it be possible that because this artifact exists, its polar opposite must also exist?' ,12 ,0,100,25,18109, ' Mograine - 15'),
        (@MOGRAINE, 15 , 0, 'Could you imagine what the material manifestation of the Light could do against the undead?' ,12 ,0,100,1,18110, ' Mograine - 16'),
        (@MOGRAINE, 16 , 0, 'It consumed the Light!' ,12 ,0,100,25,18117, ' Mograine - 17'),
        (@MOGRAINE, 17 , 0, 'BY THE LIGHT! Could it be? Could this be it?' ,12 ,0,100,5,18122, ' Mograine - 18'),
        (@MOGRAINE, 18 , 0, 'I must know... I will know.' ,12 ,0,100,5,18123, ' Mograine - 19'),
        (@MOGRAINE, 19 , 0, 'I... It... It is beautiful. What I felt when I touched it... The Light coursed through me and I through it... It healed my spirit.' ,12 ,0,100,1,18125, ' Mograine - 20'),
        (@MOGRAINE, 20 , 0, 'Let us never again speak of this day. Our enemies are many. They need not know we hold such artifacts.' ,12 ,0,100,1,18128, ' Mograine - 21'),
        (@MOGRAINE, 21 , 0, 'I have seen it... From this blessed crystal we will forge a weapon. This weapon will hold inside it a piece of each of us... And when it is used against undead, it shall cast them down. And in its wake, it will leave only ashes...' ,12 ,0,100,1,18129, ' Mograine - 22'),
        (@MOGRAINE, 22 , 0, '%s lowers his voice to a whisper.' ,16,0,100,0,18086, ' Emote - 1'),
        (@MOGRAINE, 23 , 0, 'Gasps can be heard throughout the room.' ,16,0,100,0,18090, ' Emote - 2'),
        (@MOGRAINE, 25 , 0, '%s unlocks the chest.' ,16,0,100,25,18097, ' Emote - 4'),
        (@MOGRAINE, 26 , 0, '%s removes the gauntlet from his right arm and shows everyone his mangled hand.' ,16,0,100,0,18102, ' Emote - 5'),
        (@MOGRAINE, 27 , 0, '%s shakes his head.' ,16,0,100,0,18106, ' Emote - 6'),
        (@MOGRAINE, 28 , 0, 'Shock then silence overtakes the crowd.' ,16,0,100,0,18113, ' Emote - 7'),
        (@MOGRAINE, 29 , 0, '%s reaches out to touch the light crystal.' ,16,0,100,25,18124, ' Emote - 8'),
        (@MOGRAINE, 30 , 0, '%s puts the crystal back inside the chest.' ,16,0,100,0,18127, ' Emote - 9'),
        -- Isillien
        (@ISILLIEN, 0 , 0, 'I do not see how this evil artifact is relevant to the undead. We must destroy it!' ,12 ,0,100,5,18104, ' Isillien - 1'),
        (@ISILLIEN, 1 , 0, 'Nonsense, Mograine! It must be destroyed!' ,12 ,0,100,5,18112, ' Isillien - 2'),
        (@ISILLIEN, 2 , 0, 'Your hand! It is healed!' ,12 ,0,100,25,18126, ' Isillien - 3'),
        (@ISILLIEN, 3 , 0, 'The Ashbringer...' ,12 ,0,100,66,18130, ' Isillien - 4'),
        -- Abbendis
        (@ABBENDIS, 0 , 0, 'By the Light! What is it?' ,12 ,0,100,25,18098, ' Abbendis - 1'),
        (@ABBENDIS, 1 , 0, 'The Ashbringer...' ,12 ,0,100,66,18130, ' Abbendis - 2'),
        -- Fairbanks
        (@FAIRBANKS, 0 , 0, 'Is... Is it getting lighter? Its coloration... It is changing.' ,12 ,0,100,1,18121, ' Fairbanks - 1'),
        (@FAIRBANKS, 1 , 0, 'The Ashbringer...' ,12 ,0,100,66,18130, ' Fairbanks - 2'),
        -- Tirion Fordring
        (@TIRION, 0 , 0, 'Aye, I''ve battled them as well. We are ill-prepared as a kingdom to withstand such an assault.' ,12 ,0,100,1,18093, ' Tirion - 1'),
        (@TIRION, 1 , 0, 'Impossible!' ,12 ,0,100,5,18118, ' Tirion - 2'),
        (@TIRION, 2 , 0, 'The Ashbringer...' ,12 ,0,100,66,18130, ' Tirion - 3'),
        (@TIRION, 3 , 0, '%s nods.' ,16,0,100,0,18092, ' Emote - 3'),
        -- Archanist Doan
        (@DOAN, 0 , 0, 'What do you propose, Mograine?' ,12 ,0,100,6,18094, ' Doan - 1'),
        (@DOAN, 1 , 0, 'The Ashbringer...' ,12 ,0,100,66,18130, ' Doan - 2');

        UPDATE `creature` SET `position_x`=1818.420044, `position_y`=1031.170044, `position_z`=11.0651, `orientation`=3.14155 WHERE  `guid`=@MGUID;
        UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (@MOGRAINE,@TIRION,@ABBENDIS,@FAIRBANKS,@ISILLIEN);
        UPDATE `creature_template` SET `scale` = 1.5 WHERE `entry` = @TARGET;

        DELETE FROM `creature_addon` WHERE `guid` = @MGUID;
        INSERT INTO `creature_addon` (`guid`,`bytes1`) VALUES (@MGUID,4);

        DELETE FROM `areatrigger_scripts` WHERE `entry` = @TRIGG;
        INSERT INTO `areatrigger_scripts`(`entry`, `ScriptName`) VALUES
        (@TRIGG,'SmartTrigger');

        DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@TRIGG,@MOGRAINE,@MOGRAINE*100,@TIRION,@TIRION*100,@ABBENDIS,@ABBENDIS*100,@ISILLIEN,@ISILLIEN*100,@FAIRBANKS,@FAIRBANKS*100);
        INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
        -- Trigger sets data on involved NPCs
        (@TRIGG,2,0,1,46,0,100,0,@TRIGG,0,0,0,45,1,1,0,0,0,0,10,@MGUID,@MOGRAINE,0,0,0,0,0,"Set data - On Enter inn"),
        (@TRIGG,2,1,2,61,0,100,0,@TRIGG,0,0,0,45,1,1,0,0,0,0,10,@TGUID,@TIRION,0,0,0,0,0,"Set data - On Enter inn"),
        (@TRIGG,2,2,3,61,0,100,0,@TRIGG,0,0,0,45,1,1,0,0,0,0,10,@AGUID,@ABBENDIS,0,0,0,0,0,"Set data - On Enter inn"),
        (@TRIGG,2,3,4,61,0,100,0,@TRIGG,0,0,0,45,1,1,0,0,0,0,10,@IGUID,@ISILLIEN,0,0,0,0,0,"Set data - On Enter inn"),
        (@TRIGG,2,4,5,61,0,100,0,@TRIGG,0,0,0,45,1,1,0,0,0,0,10,@FGUID,@FAIRBANKS,0,0,0,0,0,"Set data - On Enter inn"),
        -- NPCs run scripts
        (@MOGRAINE,0,0,1,38,0,100,0,1,1,@DELAY,@DELAY,80,@MOGRAINE*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - On set data - Run Script"),
        (@ISILLIEN,0,0,1,38,0,100,0,1,1,@DELAY,@DELAY,80,@ISILLIEN*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Isillien - On set data - Run Script"),
        (@TIRION,0,0,1,38,0,100,0,1,1,@DELAY,@DELAY,80,@TIRION*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tirion - On set data - Run Script"),
        (@FAIRBANKS,0,0,1,38,0,100,0,1,1,@DELAY,@DELAY,80,@FAIRBANKS*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Fairbanks - On set data - Run Script"),
        (@ABBENDIS,0,0,1,38,0,100,0,1,1,@DELAY,@DELAY,80,@ABBENDIS*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Abbendis - On set data - Run Script"),
        -- Mograine (main) script
        (@MOGRAINE*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 1"),-- 56:34.5
        (@MOGRAINE*100,9,1,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 2"),-- 39
        (@MOGRAINE*100,9,2,0,0,0,100,0,7000,7000,0,0,1,22,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote 1"), -- 46
        (@MOGRAINE*100,9,3,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 3"),-- 47
        (@MOGRAINE*100,9,4,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 4"),-- 51
        (@MOGRAINE*100,9,5,0,0,0,100,0,9000,9000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 5"), -- 00
        (@MOGRAINE*100,9,6,0,0,0,100,0,6000,6000,0,0,1,23,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote 2"), -- 06
        (@MOGRAINE*100,9,7,0,0,0,100,0,2000,2000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 6"), -- 08
        (@MOGRAINE*100,9,8,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,10,@TGUID,@TIRION,0,0,0,0,0,"Tirion - Script - Emote 3"), -- 14
        (@MOGRAINE*100,9,9,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,10,@TGUID,@TIRION,0,0,0,0,0,"Tirion - Script - Say Line 1"), -- 17
        (@MOGRAINE*100,9,10,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,10,@DGUID,@DOAN,0,0,0,0,0,"Doan - Say Line 1"), -- 23
        (@MOGRAINE*100,9,11,0,0,0,100,0,5000,5000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 7"), -- 28
        (@MOGRAINE*100,9,12,0,0,0,100,0,7000,7000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 8"), -- 35
        (@MOGRAINE*100,9,13,0,0,0,100,0,4000,4000,0,0,50,@CHEST,155,0,0,0,0,8,0,0,0,@CHESTX,@CHESTY,@CHESTZ,0,"Mograine - Script - Spawn chest"), -- 39
        (@MOGRAINE*100,9,14,0,0,0,100,0,2000,2000,0,0,1,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote 4"), -- 41
        (@MOGRAINE*100,9,15,0,0,0,100,0,1000,1000,0,0,9,0,0,0,0,0,0,15,@CHEST,10,0,0,0,0,0,"Mograine - Script - Open Chest"), -- 42
        (@MOGRAINE*100,9,16,0,0,0,100,0,0,0,0,0,12,@TARGET,1,120000,0,0,0,8,0,0,0,1816.784,1031.313,12.4703,6.265732,"Mograine - Script - Spawn dummy"), -- 42
        (@MOGRAINE*100,9,17,0,0,0,100,0,0,0,0,0,50,@DARK,110,0,0,0,0,8,0,0,0,@CHESTX,@CHESTY,@CHESTZ,0,"Mograine - Script - Spawn crystal"), -- 42
        (@MOGRAINE*100,9,18,0,0,0,100,0,2000,2000,0,0,5,34,0,0,0,0,0,10,@AGUID,@ABBENDIS,0,0,0,0,0,"Abbendis - Script - Emote"), -- 44
        (@MOGRAINE*100,9,19,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,10,@AGUID,@ABBENDIS,0,0,0,0,0,"Abbendis - Script - Say Line 1"), -- 46
        (@MOGRAINE*100,9,20,0,0,0,100,0,5000,5000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 9"), -- 50
        (@MOGRAINE*100,9,21,0,0,0,100,0,4000,4000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 10"), -- 54
        (@MOGRAINE*100,9,22,0,0,0,100,0,6000,6000,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 11"), -- 00
        (@MOGRAINE*100,9,23,0,0,0,100,0,3000,3000,0,0,1,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote 5"),
        (@MOGRAINE*100,9,24,0,0,0,100,0,4000,4000,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 12"),
        (@MOGRAINE*100,9,25,0,0,0,100,0,9000,9000,0,0,1,0,0,0,0,0,0,10,@IGUID,@ISILLIEN,0,0,0,0,0,"Isillien - Script - Say Line 1"),
        (@MOGRAINE*100,9,26,0,0,0,100,0,5000,5000,0,0,1,27,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote 6"),
        (@MOGRAINE*100,9,27,0,0,0,100,0,1000,1000,0,0,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 13"),
        (@MOGRAINE*100,9,28,0,0,0,100,0,4000,4000,0,0,1,13,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 14"),
        (@MOGRAINE*100,9,29,0,0,0,100,0,3000,3000,0,0,5,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote"),
        (@MOGRAINE*100,9,30,0,0,0,100,0,3000,3000,0,0,1,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 15"),
        (@MOGRAINE*100,9,31,0,0,0,100,0,2000,2000,0,0,5,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote"),
        (@MOGRAINE*100,9,32,0,0,0,100,0,2000,2000,0,0,1,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 16"),
        (@MOGRAINE*100,9,33,0,0,0,100,0,4000,4000,0,0,5,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote"),
        (@MOGRAINE*100,9,34,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,10,@IGUID,@ISILLIEN,0,0,0,0,0,"Isillien - Script - Say Line 2"),
        (@MOGRAINE*100,9,35,0,0,0,100,0,3000,3000,0,0,5,25,0,0,0,0,0,10,@IGUID,@ISILLIEN,0,0,0,0,0,"Isillien - Script - Emote"),
        (@MOGRAINE*100,9,36,0,0,0,100,0,5000,5000,0,0,1,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote 7"),
        (@MOGRAINE*100,9,37,0,0,0,100,0,0,0,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote"), -- 52
        (@MOGRAINE*100,9,38,0,0,0,100,0,2000,2000,0,0,91,@MGUID,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Set unit bytes"),
        (@MOGRAINE*100,9,39,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,1818.665,1029.883,11.09751,2.553278,"Mograine - Script - Start WP"),
        (@MOGRAINE*100,9,40,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,15,@CHEST,50,0,0,0,0,0,"Mograine - Script - Set orientation"),
        (@MOGRAINE*100,9,41,0,0,0,100,0,4000,4000,0,0,1,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 17"), -- 58
        (@MOGRAINE*100,9,42,0,0,0,100,0,2000,2000,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote"), -- 00
        (@MOGRAINE*100,9,43,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,10,@TGUID,@TIRION,0,0,0,0,0,"Tirion - Say Line 2"), -- 03
        (@MOGRAINE*100,9,44,0,0,0,100,0,9000,9000,0,0,1,0,0,0,0,0,0,10,@FGUID,@FAIRBANKS,0,0,0,0,0,"Fairbanks - Say Line 2"), -- 11
        (@MOGRAINE*100,9,45,0,0,0,100,0,20000,20000,0,0,50,@LIGHT,32,0,0,0,0,8,0,0,0,1816.681,1031.386,12.78501,0,"Mograine - Script - Spawn crystal"),
        (@MOGRAINE*100,9,46,0,0,0,100,0,3000,3000,0,0,1,17,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 18"), -- 34
        (@MOGRAINE*100,9,47,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote"), -- 36
        (@MOGRAINE*100,9,48,0,0,0,100,0,2000,2000,0,0,1,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 19"), -- 38
        (@MOGRAINE*100,9,49,0,0,0,100,0,4000,4000,0,0,1,29,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote 8"), -- 42
        (@MOGRAINE*100,9,50,0,0,0,100,0,1500,1500,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote"),
        (@MOGRAINE*100,9,51,0,0,0,100,0,0,0,0,0,11,@TBTL,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Cast TBLT"),
        (@MOGRAINE*100,9,52,0,0,0,100,0,4000,4000,0,0,5,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote"),
        (@MOGRAINE*100,9,53,0,0,0,100,0,7000,7000,0,0,1,19,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 20"),
        (@MOGRAINE*100,9,54,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,10,@IGUID,@ISILLIEN,0,0,0,0,0,"Isillien - Script - Say Line 3"),
        (@MOGRAINE*100,9,55,0,0,0,100,0,4000,4000,0,0,1,30,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Emote 9"),
        (@MOGRAINE*100,9,56,0,0,0,100,0,0,0,0,0,32,0,0,0,0,0,0,15,@CHEST,10,0,0,0,0,0,"Mograine - Script - Close Chest"),
        (@MOGRAINE*100,9,57,0,0,0,100,0,4000,4000,0,0,1,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 21"),
        (@MOGRAINE*100,9,58,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,1818.346,1031.224,11.09751,3.124123,"Mograine - Script - Start WP"),
        (@MOGRAINE*100,9,59,0,0,0,100,0,500,500,0,0,50,@CHAIR,5000,0,0,0,0,8,0,0,0,1818.346,1031.224,11.09751,3.124123,"Mograine - Script - Spawn chair"),
        (@MOGRAINE*100,9,60,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,10,@TGUID,@TIRION,0,0,0,0,0,"Mograine - Script - Set orientation"),
        (@MOGRAINE*100,9,61,0,0,0,100,0,0,0,0,0,90,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Set unit bytes"),
        (@MOGRAINE*100,9,62,0,0,0,100,0,8000,8000,0,0,1,21,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mograine - Script - Say Line 22"),
        (@MOGRAINE*100,9,63,0,0,0,100,0,11000,11000,0,0,1,2,0,0,0,0,0,10,@TGUID,@TIRION,0,0,0,0,0,"Tirion - Say Line 3"),
        (@MOGRAINE*100,9,64,0,0,0,100,0,3000,3000,0,0,1,3,0,0,0,0,0,10,@IGUID,@ISILLIEN,0,0,0,0,0,"Isillien - Script - Say line 4"),
        (@MOGRAINE*100,9,65,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,10,@DGUID,@DOAN,0,0,0,0,0,"Doan - Script - Say line 2"),
        (@MOGRAINE*100,9,66,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,10,@FGUID,@FAIRBANKS,0,0,0,0,0,"Fairbanks - Script - Say line 2"),
        (@MOGRAINE*100,9,67,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,10,@AGUID,@ABBENDIS,0,0,0,0,0,"Abbendis - Script - Say line 2"),
        -- Tirion script
        (@TIRION*100,9,0,0,0,0,100,0,0,0,0,0,50,@CHAIR,215,0,0,0,0,8,0,0,0,1818.346,1031.224,11.09751,3.124123,"Mograine - Script - Spawn chair"),
        (@TIRION*100,9,1,0,0,0,100,0,152000,152000,0,0,11,@SHOCK,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tirion - Script - Cast Holy Shock"),
        (@TIRION*100,9,2,0,0,0,100,0,12500,12500,0,0,11,@SHOCK,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tirion - Script - Cast Holy Shock"),
        (@TIRION*100,9,3,0,0,0,100,0,3500,3500,0,0,11,@JUDGE,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tirion - Script - Cast Judgement"),
        (@TIRION*100,9,4,0,0,0,100,0,2000,2000,0,0,11,@JUDGE,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tirion - Script - Cast Judgement"),
        (@TIRION*100,9,5,0,0,0,100,0,2500,2500,0,0,11,@HEALS,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tirion - Script - Cast Heal"),
        (@TIRION*100,9,6,0,0,0,100,0,4000,4000,0,0,11,@SHOCK,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tirion - Script - Cast Holy Shock"),
        -- Fairbanks script
        (@FAIRBANKS*100,9,0,0,0,0,100,0,155000,155000,0,0,66,0,0,0,0,0,0,15,@CHEST,50,0,0,0,0,0,"Fairbanks - Script - Set orientation"),
        (@FAIRBANKS*100,9,1,0,0,0,100,0,6000,6000,0,0,11,@HEALS,2,0,0,0,0,1,0,0,0,0,0,0,0,"Fairbanks - Script - Cast Heal"),
        (@FAIRBANKS*100,9,2,0,0,0,100,0,5000,5000,0,0,11,@SMITE,2,0,0,0,0,1,0,0,0,0,0,0,0,"Fairbanks - Script - Cast Smite"),
        (@FAIRBANKS*100,9,3,0,0,0,100,0,2500,2500,0,0,11,@HEALS,2,0,0,0,0,1,0,0,0,0,0,0,0,"Fairbanks - Script - Cast Heal"),
        (@FAIRBANKS*100,9,4,0,0,0,100,0,2500,2500,0,0,11,@SMITE,2,0,0,0,0,1,0,0,0,0,0,0,0,"Fairbanks - Script - Cast Smite"),
        (@FAIRBANKS*100,9,5,0,0,0,100,0,2500,2500,0,0,11,@SMITE,2,0,0,0,0,1,0,0,0,0,0,0,0,"Fairbanks - Script - Cast Smite"),
        (@FAIRBANKS*100,9,6,0,0,0,100,0,2500,2500,0,0,11,@HEALS,2,0,0,0,0,1,0,0,0,0,0,0,0,"Fairbanks - Script - Cast Heal"),
        (@FAIRBANKS*100,9,7,0,0,0,100,0,70000,70000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fairbanks - Script - Set orientation"),
        -- Abbendis script
        (@ABBENDIS*100,9,0,0,0,0,100,0,68500,68500,0,0,66,0,0,0,0,0,0,15,@CHEST,50,0,0,0,0,0,"Abbendis - Script - Set orientation"),
        (@ABBENDIS*100,9,1,0,0,0,100,0,96000,96000,0,0,11,@SHOCK,2,0,0,0,0,1,0,0,0,0,0,0,0,"Abbendis - Script - Cast Holy Shock"),
        (@ABBENDIS*100,9,2,0,0,0,100,0,3500,3500,0,0,11,@JUDGE,2,0,0,0,0,1,0,0,0,0,0,0,0,"Abbendis - Script - Cast Judgement"),
        (@ABBENDIS*100,9,3,0,0,0,100,0,3500,3500,0,0,11,@SHOCK,2,0,0,0,0,1,0,0,0,0,0,0,0,"Abbendis - Script - Cast Holy Shock"),
        (@ABBENDIS*100,9,4,0,0,0,100,0,5000,5000,0,0,11,@HEALS,2,0,0,0,0,1,0,0,0,0,0,0,0,"Abbendis - Script - Cast Heal"),
        (@ABBENDIS*100,9,5,0,0,0,100,0,2500,2500,0,0,11,@SHOCK,2,0,0,0,0,1,0,0,0,0,0,0,0,"Abbendis - Script - Cast Holy Shock"),
        (@ABBENDIS*100,9,6,0,0,0,100,0,67000,67000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Abbendis - Script - Set orientation"),
        -- Isillien script
        (@ISILLIEN*100,9,0,0,0,0,100,0,68000,68000,0,0,66,0,0,0,0,0,0,15,@CHEST,50,0,0,0,0,0,"Isillien - Script - Set orientation"),
        (@ISILLIEN*100,9,1,0,0,0,100,0,66000,66000,0,0,11,@SMITE,2,0,0,0,0,1,0,0,0,0,0,0,0,"Isillien - Script - Cast Smite"),
        (@ISILLIEN*100,9,2,0,0,0,100,0,32000,32000,0,0,11,@SMITE,2,0,0,0,0,1,0,0,0,0,0,0,0,"Isillien - Script - Cast Smite"),
        (@ISILLIEN*100,9,3,0,0,0,100,0,2500,2500,0,0,11,@HEALS,2,0,0,0,0,1,0,0,0,0,0,0,0,"Isillien - Script - Cast Heal"),
        (@ISILLIEN*100,9,4,0,0,0,100,0,2500,2500,0,0,11,@SMITE,2,0,0,0,0,1,0,0,0,0,0,0,0,"Isillien - Script - Cast Smite"),
        (@ISILLIEN*100,9,5,0,0,0,100,0,2500,2500,0,0,11,@SMITE,2,0,0,0,0,1,0,0,0,0,0,0,0,"Isillien - Script - Cast Smite"),
        (@ISILLIEN*100,9,6,0,0,0,100,0,2500,2500,0,0,11,@HEALS,2,0,0,0,0,1,0,0,0,0,0,0,0,"Isillien - Script - Cast Heal"),
        (@ISILLIEN*100,9,7,0,0,0,100,0,70000,70000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Isillien - Script - Set orientation");
