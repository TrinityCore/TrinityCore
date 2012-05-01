-- Q 12491, 12492 - Худое варево Худовара
-- Q 11441, 11446 - Хмельной фестиваль!
-- Q 11122, 11412 - Туда и обратно
-- Q 11118, 11120 - Розовые элекки на марше
-- Q 11117, 11431 - Поймать дикого зайцелопа!
-- Q 11293 - Пивоварня Ячменоваров ищет зазывалу!
-- Q 11408 - Пивоварня Т'чали Вуду ищет зазывалу!
-- Q 11407 - Пивоварня Дрона ищет зазывалу!
-- Q 11294 - Пивоварня Громоваров ищет зазывалу!
-- Q 29393, 29394 - Пиво для Хмельного фестиваля
-- Q 12022, 12191 - Пей до дна!
-- Q 12020, 12192 - Однажды, напившись в...
-- Q 29397, 29396 - Новый продавец сувениров
-- Q 12278, 12306, 12420, 12421 - Клуб "Пиво месяца"
-- Q 11318, 11409 - А теперь гонки на баранах... Или вроде того.
-- 12491, 12492, 11441, 11446, 11122, 11412, 11118, 11120, 11117, 11431, 11293, 11408, 11407, 11294, 29393, 29394, 12022, 12191, 12020, 12192, 
-- 29397, 29396, 12306, 12420, 12421, 11318, 11409

-- <Распорядитель Хмельного фестиваля>
-- Q12491 Худое варево Худовара
-- Q12492 Худое варево Худовара
-- Misc.
-- Areatrigger scriptname
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (4829, 4820);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4829, 'at_brewfest'), -- Durotar
(4820, 'at_brewfest'); -- Dun Morogh

-- Ипфелькофер Железный Бочонок (A) 24710
SET @ENTRY := 24710;
SET @SPELL_GROW := 50551;
SET @SPELL_DRINK := 50552;
SET @SPELL_FINISH := 50555;
SET @QUEST_DIRE_BREW := 12491;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY, @ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 20, 0, 100, 0, @QUEST_DIRE_BREW, 0, 0, 0, 80, @ENTRY*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ipfelkofer Ironkeg - On Quest Complete - Run Script"), 
(@ENTRY*100+0, 9, 0, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, "Ipfelkofer Ironkeg - On Script - Say Line 0"), 
(@ENTRY*100+0, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @SPELL_DRINK, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "Ipfelkofer Ironkeg - On Script - Cast Questgiver Tries Dire Brew"), 
(@ENTRY*100+0, 9, 2, 0, 0, 0, 100, 0, 8500, 8500, 0, 0, 11, @SPELL_FINISH, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "Ipfelkofer Ironkeg - On Script - Cast Questgiver Finishes Drinking"), 
(@ENTRY*100+0, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, @SPELL_GROW, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "Ipfelkofer Ironkeg - On Script - Remove Growth Aura"), 
(@ENTRY*100+0, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, "Ipfelkofer Ironkeg - On Script - Say Line 1"), 
(@ENTRY*100+0, 9, 5, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, "Ipfelkofer Ironkeg - On Script - Say Line 2"), 
(@ENTRY*100+0, 9, 6, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, "Ipfelkofer Ironkeg - On Script - Say Line 3");
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `TEXT`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ENTRY, 0, 0, "Right! Let's try this so-called dire brew...", 12, 0, 100, 0, 0, 0, "Ipfelkofer Ironkeg"), 
(@ENTRY, 1, 0, "Bronzebeard's beard! What a drink!", 12, 0, 100, 0, 0, 0, "Ipfelkofer Ironkeg"), 
(@ENTRY, 2, 0, "$N, this beer... well, it might be the best of Brewfest!", 12, 0, 100, 15, 0, 0, "Ipfelkofer Ironkeg"), 
(@ENTRY, 3, 0, "It is a shame Coren's Dire Brew can't quench more thirsting throats! It's blasphemy, I know, but I envy those Dark Iron dwarves!", 12, 0, 100, 274, 0, 0, "Ipfelkofer Ironkeg"), 
(@ENTRY, 4, 0, "Ho there, and welcome to Brewfest!", 12, 7, 100, 3, 0, 0, "Ipfelkofer Ironkeg"), 
(@ENTRY, 4, 1, "Hello, friend! Welcome to the Brewfest Grounds!", 12, 7, 100, 3, 0, 0, "Ipfelkofer Ironkeg"), 
(@ENTRY, 4, 2, "Hail, good $c! Welcome to Ironforge's annual Brewfest celebration!", 12, 7, 100, 3, 0, 0, "Ipfelkofer Ironkeg");
 
-- Слухарь Жмухли (H) 24711
SET @ENTRY := 24711;
SET @SPELL_GROW := 50551;
SET @SPELL_DRINK := 50552;
SET @SPELL_FINISH := 50555;
SET @QUEST_DIRE_BREW := 12492;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY, @ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 20, 0, 100, 0, @QUEST_DIRE_BREW, 0, 0, 0, 80, @ENTRY*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tapper Swindlekeg - On Quest Complete - Run Script"), 
(@ENTRY*100+0, 9, 0, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, "Tapper Swindlekeg - On Script - Say Line 0"), 
(@ENTRY*100+0, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @SPELL_DRINK, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "Tapper Swindlekeg - On Script - Cast Questgiver Tries Dire Brew"), 
(@ENTRY*100+0, 9, 2, 0, 0, 0, 100, 0, 8500, 8500, 0, 0, 11, @SPELL_FINISH, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "Tapper Swindlekeg - On Script - Cast Questgiver Finishes Drinking"), 
(@ENTRY*100+0, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, @SPELL_GROW, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "Tapper Swindlekeg - On Script - Remove Growth Aura"), 
(@ENTRY*100+0, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, "Tapper Swindlekeg - On Script - Say Line 1"), 
(@ENTRY*100+0, 9, 5, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, "Tapper Swindlekeg - On Script - Say Line 2"), 
(@ENTRY*100+0, 9, 6, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, "Tapper Swindlekeg - On Script - Say Line 3");
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `TEXT`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ENTRY, 0, 0, "Well time's money, and time's wasting! Let's have that drink...", 12, 0, 100, 1, 0, 0, "Tapper Swindlekeg"), 
(@ENTRY, 1, 0, "Wow! This really greases the steamplugs!", 12, 0, 100, 1, 0, 0, "Tapper Swindlekeg"), 
(@ENTRY, 2, 0, "If I were an honest goblin, I'd say this was the best beer of the festival...", 12, 0, 100, 1, 0, 0, "Tapper Swindlekeg"), 
(@ENTRY, 3, 0, "Too bad Coren's dead. If I could buy that brew from him and resell it - watered down and rebottled under my own label, of course - I'd be rich!", 12, 0, 100, 1, 0, 0, "Tapper Swindlekeg"), 
(@ENTRY, 4, 0, "Hey there, and welcome to Brewfest. Come in and have a drink or three!", 12, 1, 100, 3, 0, 0, "Tapper Swindlekeg"), 
(@ENTRY, 4, 1, "What's up, friend? Welcome to the Brewfest Grounds! Now go buy some drinks!", 12, 1, 100, 3, 0, 0, "Tapper Swindlekeg"), 
(@ENTRY, 4, 2, "Hey hey, it's another $r! Welcome to my annual Brewfest celebration... now go feast and drink some!", 12, 1, 100, 3, 0, 0, "Tapper Swindlekeg");




-- Q11117 [A] Поймать дикого зайцелопа!
DELETE FROM `creature_questrelation` WHERE `quest` = 11117;
DELETE FROM `creature_involvedrelation` WHERE `quest` = 11117;
-- 
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (23486, 11117);
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (23486, 11117);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`=23486;
-- Q11431 [H] Поймать дикого зайцелопа!
DELETE FROM `creature_questrelation` WHERE `quest` = 11431;
DELETE FROM `creature_involvedrelation` WHERE `quest` = 11431;
-- 
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (24657, 11431);
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (24657, 11431);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`=24657;
-- Дикий зайцелоп
-- 1 одеть очки, чтобы увидеть зайцев, берутся у нпс по госсипу
SET @ENTRY := 23487;
SET @SPELL_NET := 41621;
SET @SPELL_CREATE_ITEM := 41622;
UPDATE `creature_template` SET `AIName`='SmartAI', `unit_flags`=640  WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, @SPELL_NET, 0, 0, 0, 11, @SPELL_CREATE_ITEM, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wild Wolpertinger - On Spellhit - Cast Create Stunned Wolpertinger Item'), 
(@ENTRY, 0, 1, 0, 61, 1, 100, 0, 0, 0, 0, 0, 41, 300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wild Wolpertinger - On Spellhit - Forced Despawn');




-- Вышагивающий розовый элекк, появляются только после употребления Дренейский светлый эль. 
DELETE FROM `creature_template_addon` WHERE `entry`=27958;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(27958, 0, 0, 0, 0, '36440');

-- [Q]11118 [A] Розовые элекки на марше
DELETE FROM `creature_questrelation` WHERE `quest` = 11118;
DELETE FROM `creature_involvedrelation` WHERE `quest` = 11118;
-- 
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (23486, 11118);
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (23486, 11118);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`= 23486;
-- [Q]11120 [H] Розовые элекки на марше
DELETE FROM `creature_questrelation` WHERE `quest` = 11120;
DELETE FROM `creature_involvedrelation` WHERE `quest` = 11120;
-- 
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (24657, 11120);
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (24657, 11120);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`= 24657;

-- NPC *** розовый элекк
DELETE FROM `creature_template_addon` WHERE `entry` IN (23507, 23527, 23528, 23529, 23530, 23531);
SET @SPELL_ELEKK_DISPERSION := 44654;
SET @SPELL_DRUNK_INVISIBILITY := 36440;
-- Tirisfal Pink Elekk SAI
SET @ENTRY := 23530;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 19, @ENTRY, 0, 0, 0, 0, 0, 0, 'Tirisfal Pink Elekk - set faction'), 
(@ENTRY, 0, 1, 0, 23, 0, 100, 0, @SPELL_DRUNK_INVISIBILITY, 0, 2000, 2000, 11, @SPELL_DRUNK_INVISIBILITY, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tirisfal Pink Elekk - Drunk Invisibility (Pink) not present - Aura Drunk Invisibility (Pink)'), 
(@ENTRY, 0, 2, 2, 8, 0, 100, 0, @SPELL_ELEKK_DISPERSION, 0, 0, 0, 33, @ENTRY, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Tirisfal Pink Elekk - On Spellhit - Give quest credit'), 
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tirisfal Pink Elekk - On Spellhit - Forced Despawn');
-- Eversong Pink Elekk SAI
SET @ENTRY := 23531;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 19, @ENTRY, 0, 0, 0, 0, 0, 0, 'Eversong Pink Elekk - set faction'), 
(@ENTRY, 0, 1, 0, 23, 0, 100, 0, @SPELL_DRUNK_INVISIBILITY, 0, 2000, 2000, 11, @SPELL_DRUNK_INVISIBILITY, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eversong Pink Elekk - Drunk Invisibility (Pink) not present - Aura Drunk Invisibility (Pink)'), 
(@ENTRY, 0, 2, 2, 8, 0, 100, 0, @SPELL_ELEKK_DISPERSION, 0, 0, 0, 33, @ENTRY, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eversong Pink Elekk - On Spellhit - Give quest credit'), 
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eversong Pink Elekk - On Spellhit - Forced Despawn');
-- Mulgore Pink Elekk SAI
SET @ENTRY := 23529;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 19, @ENTRY, 0, 0, 0, 0, 0, 0, 'Mulgore Pink Elekk - set faction'), 
(@ENTRY, 0, 1, 0, 23, 0, 100, 0, @SPELL_DRUNK_INVISIBILITY, 0, 2000, 2000, 11, @SPELL_DRUNK_INVISIBILITY, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mulgore Pink Elekk - Drunk Invisibility (Pink) not present - Aura Drunk Invisibility (Pink)'), 
(@ENTRY, 0, 2, 2, 8, 0, 100, 0, @SPELL_ELEKK_DISPERSION, 0, 0, 0, 33, @ENTRY, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mulgore Pink Elekk - On Spellhit - Give quest credit'), 
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mulgore Pink Elekk - On Spellhit - Forced Despawn');
-- Elwynn Pink Elekk SAI
SET @ENTRY := 23507;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 19, @ENTRY, 0, 0, 0, 0, 0, 0, 'Elwynn Pink Elekk - set faction'), 
(@ENTRY, 0, 1, 0, 23, 0, 100, 0, @SPELL_DRUNK_INVISIBILITY, 0, 2000, 2000, 11, @SPELL_DRUNK_INVISIBILITY, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elwynn Pink Elekk - Drunk Invisibility (Pink) not present - Aura Drunk Invisibility (Pink)'), 
(@ENTRY, 0, 2, 2, 8, 0, 100, 0, @SPELL_ELEKK_DISPERSION, 0, 0, 0, 33, @ENTRY, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elwynn Pink Elekk - On Spellhit - Give quest credit'), 
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Elwynn Pink Elekk - On Spellhit - Forced Despawn');
-- Teldrassil Pink Elekk SAI
SET @ENTRY := 23527;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 19, @ENTRY, 0, 0, 0, 0, 0, 0, 'Teldrassil Pink Elekk - set faction'), 
(@ENTRY, 0, 1, 0, 23, 0, 100, 0, @SPELL_DRUNK_INVISIBILITY, 0, 2000, 2000, 11, @SPELL_DRUNK_INVISIBILITY, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Teldrassil Pink Elekk - Drunk Invisibility (Pink) not present - Aura Drunk Invisibility (Pink)'), 
(@ENTRY, 0, 2, 2, 8, 0, 100, 0, @SPELL_ELEKK_DISPERSION, 0, 0, 0, 33, @ENTRY, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Teldrassil Pink Elekk - On Spellhit - Give quest credit'), 
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Teldrassil Pink Elekk - On Spellhit - Forced Despawn');
-- Azuremyst Pink Elekk SAI
SET @ENTRY := 23528;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 19, @ENTRY, 0, 0, 0, 0, 0, 0, 'Azuremyst Pink Elekk - set faction'), 
(@ENTRY, 0, 1, 0, 23, 0, 100, 0, @SPELL_DRUNK_INVISIBILITY, 0, 2000, 2000, 11, @SPELL_DRUNK_INVISIBILITY, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Azuremyst Pink Elekk - Drunk Invisibility (Pink) not present - Aura Drunk Invisibility (Pink)'), 
(@ENTRY, 0, 2, 2, 8, 0, 100, 0, @SPELL_ELEKK_DISPERSION, 0, 0, 0, 33, @ENTRY, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Azuremyst Pink Elekk - On Spellhit - Give quest credit'), 
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Azuremyst Pink Elekk - On Spellhit - Forced Despawn');



-- Q 11293 - Пивоварня Ячменоваров ищет зазывалу!
-- Q 11408 - Пивоварня Т'чали Вуду ищет зазывалу!
-- Q 11407 - Пивоварня Дрона ищет зазывалу!
-- Q 11294 - Пивоварня Громоваров ищет зазывалу!
-- Q 11122, 11412 - Туда и обратно

-- ScriptNames
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_brewfest_speed';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(42992, 'spell_brewfest_speed'), 
(42993, 'spell_brewfest_speed'), 
(42994, 'spell_brewfest_speed'), 
(43310, 'spell_brewfest_speed'), 
(43332, 'spell_brewfest_speed');
-- Ram Barrel Run Quest
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-43880, -43883, 42994, 42993, 42992, 43310, 43332, -43332);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-43883, -42146, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43883, -42992, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43883, -42993, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43883, -42994, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43883, -43052, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43883, -43310, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43883, -43332, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43883, -43492, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43880, -43492, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43880, -43332, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43880, -43310, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43880, -43052, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43880, -42994, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43880, -42993, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43880, -42992, 0, 'Remove brewfest speed buffs when player dismounted'), 
(-43880, -42146, 0, 'Remove brewfest speed buffs when player dismounted'), 
(42992, -43332, 0, 'Switch brewfest speed buffs - Exhausted'), 
(42992, -43310, 0, 'Switch brewfest speed buffs - Neutral'), 
(42992, -42994, 0, 'Switch brewfest speed buffs - Gallop'), 
(42992, -42993, 0, 'Switch brewfest speed buffs - Canter'), 
(42993, -43332, 0, 'Switch brewfest speed buffs - Exhausted'), 
(42993, -43310, 0, 'Switch brewfest speed buffs - Neutral'), 
(42993, -42994, 0, 'Switch brewfest speed buffs - Gallop'), 
(42993, -42992, 0, 'Switch brewfest speed buffs - Trot'), 
(42994, -43332, 0, 'Switch brewfest speed buffs - Exhausted'), 
(42994, -43310, 0, 'Switch brewfest speed buffs - Neutral'), 
(42994, -42993, 0, 'Switch brewfest speed buffs - Canter'), 
(42994, -42992, 0, 'Switch brewfest speed buffs - Trot'), 
(43310, -43332, 0, 'Switch brewfest speed buffs - Exhausted'), 
(43310, -42994, 0, 'Switch brewfest speed buffs - Gallop'), 
(43310, -42993, 0, 'Switch brewfest speed buffs - Canter'), 
(43310, -42992, 0, 'Switch brewfest speed buffs - Trot'), 
(-43332, 43310, 0, 'Switch brewfest speed buffs - Neutral'), 
(43332, -43310, 0, 'Switch brewfest speed buffs - Neutral'), 
(43332, -42994, 0, 'Switch brewfest speed buffs - Gallop'), 
(43332, -42993, 0, 'Switch brewfest speed buffs - Canter'), 
(43332, -42992, 0, 'Switch brewfest speed buffs - Trot');

-- Spell Арендованный скаковой баран
UPDATE `quest_template` SET `SrcSpell`=43883 WHERE `entry` IN (11293, 11294, 11407, 11408, 11318, 11409, 11122, 11412);

DELETE FROM `creature_questrelation` WHERE `quest` = 12194;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (24510, 12194);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry` = 24510;

-- Q 11122, 11412 - Туда и обратно
-- [DND] Brewfest Delivery Bunny
SET @ID := 24337;
SET @GUID := 497198; -- заменить
DELETE FROM `creature` WHERE `id`=@ID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@GUID, @ID, 0, 1, 1, 0, 0, -5498.16, -511.732, 397.462, 1.85111, 300, 0, 0, 42, 0, 0, 0, 0, 0), 
(@GUID+1, @ID, 1, 1, 1, 0, 0, 1004.55, -4479.3, 10.9096, -0.244346, 180, 0, 0, 42, 0, 0, 0, 0, 0), 
(@GUID+2, @ID, 1, 1, 1, 0, 0, 1096.65, -4427.11, 20.2013, 2.3911, 180, 0, 0, 42, 0, 0, 0, 0, 0), 
(@GUID+3, @ID, 1, 1, 1, 0, 0, 1290.86, -4433.25, 27.1411, 2.05949, 180, 0, 0, 42, 0, 0, 0, 0, 0), 
(@GUID+4, @ID, 0, 1, 1, 0, 0, -5189.16, -482.752, 387.244, -1.65806, 180, 0, 0, 42, 0, 0, 0, 0, 0), 
(@GUID+5, @ID, 0, 1, 1, 0, 0, -5355.3, -527.423, 391.493, -2.3911, 180, 0, 0, 42, 0, 0, 0, 0, 0), 
(@GUID+6, @ID, 0, 1, 1, 0, 0, -5667.41, -476.651, 396.275, -2.00713, 180, 0, 0, 42, 0, 0, 0, 0, 0);

-- Fix equipment templates [Monster - Item, Tankard Gold (Yellow Glow)]
DELETE FROM `creature_equip_template` WHERE (`entry`=2478);
INSERT INTO `creature_equip_template` VALUES (2478, 33161, 33161, 0);
UPDATE `creature_template` SET `equipment_id`=2478 WHERE `entry` IN 
(23684, 23683, 23685, 24493, 24492);

-- Ита Громовар <Официантка>
SET @ENTRY := 23684;
SET @SPELL_DRINK := 42518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 22, 0, 100, 0, 101, 5000, 5000, 0, 11, @SPELL_DRINK, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Ita Thunderbrew - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"), 
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 30000, 45000, 180000, 240000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Ita Thunderbrew - Out of Combat - Yell Line 0 (random)"), 
(@ENTRY, 0, 2, 0, 38, 0, 100, 0, 3, 3, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ita Thunderbrew - On Data Set - Set Phase 1"), 
(@ENTRY, 0, 3, 0, 1, 1, 100, 0, 10000, 35000, 45000, 50000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Ita Thunderbrew - Out of Combat - Say Line 2 (random) (P1)"), 
(@ENTRY, 0, 4, 0, 1, 1, 100, 1, 3, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ita Thunderbrew - Out of Combat - Yell Line 1 (P1)"), 
(@ENTRY, 0, 5, 0, 52, 1, 100, 0, 1, @ENTRY, 0, 0, 50, 186471, 15000, 0, 0, 0, 0, 8, 0, 0, 0, -5149.791992, -590.198792, 397.323730, 4.39, "Ita Thunderbrew - On Text Over - Summon Super Brew Stein Trap (P1)"), 
(@ENTRY, 0, 6, 0, 38, 0, 100, 0, 4, 4, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ita Thunderbrew - On Data Set - Set Phase 0"); -- Event is over, so set phase 0
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ENTRY, 0, 0, "Thunderbrew, finest brewery in all the realms.", 12, 0, 100, 1, 0, 0, "Ita Thunderbrew"), 
(@ENTRY, 0, 1, "THUNDER! THUNDER! THUNDER! THUNDERBREW, HO!", 12, 0, 100, 1, 0, 0, "Ita Thunderbrew"), 
(@ENTRY, 0, 2, "You look like you could use a cold one. Thunderbrew's got ya covered!", 12, 0, 100, 1, 0, 0, "Ita Thunderbrew"), 
(@ENTRY, 1, 0, "SOMEONE TRY THIS SUPER BREW!", 14, 0, 100, 0, 0, 0, "Ita Thunderbrew"), 
(@ENTRY, 2, 0, "Chug and chuck! Chug and chuck!", 12, 0, 100, 1, 0, 0, "Ita Thunderbrew"), 
(@ENTRY, 2, 1, "Down the free brew and pelt the Guzzlers with your mug!", 12, 0, 100, 1, 0, 0, "Ita Thunderbrew");
 
-- Майев Ячменовар <Официантка>
SET @ENTRY := 23683;
SET @SPELL_DRINK := 42518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 22, 0, 100, 0, 101, 5000, 5000, 0, 11, @SPELL_DRINK, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Maeve Barleybrew - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"), 
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 30000, 45000, 180000, 240000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Maeve Barleybrew - Out of Combat - Yell Line 0 (random)"), 
(@ENTRY, 0, 2, 0, 38, 0, 100, 0, 3, 3, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Maeve Barleybrew - On Data Set - Set Phase 1"), 
(@ENTRY, 0, 3, 0, 1, 1, 100, 0, 10000, 35000, 45000, 50000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Maeve Barleybrew - Out of Combat - Say Line 2 (random) (P1)"), 
(@ENTRY, 0, 4, 0, 1, 1, 100, 1, 3, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Maeve Barleybrew - Out of Combat - Yell Line 1 (P1)"), 
(@ENTRY, 0, 5, 0, 52, 1, 100, 0, 1, @ENTRY, 0, 0, 50, 186471, 15000, 0, 0, 0, 0, 8, 0, 0, 0, -5161.600586, -611.307861, 397.917419, 2.39, "Maeve Barleybrew - On Text Over - Summon Super Brew Stein Trap (P1)"), 
(@ENTRY, 0, 6, 0, 38, 0, 100, 0, 4, 4, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Maeve Barleybrew - On Data Set - Set Phase 0"); -- Event is over, so set phase 0
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ENTRY, 0, 0, "Come try our Barleybrew Dark!", 12, 0, 100, 1, 0, 0, "Maeve Barleybrew"), 
(@ENTRY, 0, 1, "Barleybrew, finest brewery in Azeroth!", 12, 0, 100, 1, 0, 0, "Maeve Barleybrew"), 
(@ENTRY, 0, 2, "The Barleybrews have always been leaders in brewery innovation. Check out our newest creation, Barleybrew Clear!", 12, 0, 100, 1, 0, 0, "Maeve Barleybrew"), 
(@ENTRY, 1, 0, "SOMEONE TRY THIS SUPER BREW!", 14, 0, 100, 0, 0, 0, "Maeve Barleybrew"), 
(@ENTRY, 2, 0, "Chug and chuck! Chug and chuck!", 12, 0, 100, 1, 0, 0, "Maeve Barleybrew"), 
(@ENTRY, 2, 1, "Down the free brew and pelt the Guzzlers with your mug!", 12, 0, 100, 1, 0, 0, "Maeve Barleybrew");

-- Зазывала вудуистской пивоварни Т'чали
SET @ENTRY := 24493;
SET @SPELL_DRINK := 42518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 22, 0, 100, 0, 101, 5000, 5000, 0, 11, @SPELL_DRINK, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "T'chali's Voodoo Brewery Barker - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"), 
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 30000, 45000, 180000, 240000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "T'chali's Voodoo Brewery Barker - Out of Combat - Yell Line 0 (random)"), 
(@ENTRY, 0, 2, 0, 38, 0, 100, 0, 3, 3, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "T'chali's Voodoo Brewery Barker - On Data Set - Set Phase 1"), 
(@ENTRY, 0, 3, 0, 1, 1, 100, 0, 10000, 35000, 45000, 50000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "T'chali's Voodoo Brewery Barker - Out of Combat - Say Line 2 (random) (P1)"), 
(@ENTRY, 0, 4, 0, 1, 1, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "T'chali's Voodoo Brewery Barker - Out of Combat - Yell Line 1 (P1)"), 
(@ENTRY, 0, 5, 0, 52, 1, 100, 0, 1, @ENTRY, 0, 0, 50, 186471, 15000, 0, 0, 0, 0, 8, 0, 0, 0, 1190.705688, -4285.604004, 21.193674, 4.39, "T'chali's Voodoo Brewery Barker - On Text Over - Summon Super Brew Stein Trap (P1)"), 
(@ENTRY, 0, 6, 0, 38, 0, 100, 0, 4, 4, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "T'chali's Voodoo Brewery Barker - On Data Set - Set Phase 0"); -- Event is over, so set phase 0
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ENTRY, 0, 0, "If you wanna live life to the fullest, you gotta try T'chali's Voodoo Brew!", 12, 0, 100, 1, 0, 0, "T'chali's Voodoo Brewery Barker"), 
(@ENTRY, 0, 1, "T'chali's Voodoo Brews helps keep the party going! Check out the party at Brewfest!", 12, 0, 100, 1, 0, 0, "T'chali's Voodoo Brewery Barker"), 
(@ENTRY, 0, 2, "Hey you! T'chali's Voodoo Brewers have got a brew that won't kill you! But they've also got a brew that might...", 12, 0, 100, 1, 0, 0, "T'chali's Voodoo Brewery Barker"), 
(@ENTRY, 0, 3, "T'chali's Voodoo Brewery has the best brew you can find! They were voted 'Best Brew' by the Goblin Brew Weekly!", 12, 0, 100, 1, 0, 0, "T'chali's Voodoo Brewery Barker"), 
(@ENTRY, 1, 0, "SOMEONE TRY THIS SUPER BREW!", 14, 0, 100, 0, 0, 0, "T'chali's Voodoo Brewery Barker"), 
(@ENTRY, 2, 0, "Chug and chuck! Chug and chuck!", 12, 0, 100, 1, 0, 0, "T'chali's Voodoo Brewery Barker"), 
(@ENTRY, 2, 1, "Down the free brew and pelt the Guzzlers with your mug!", 12, 0, 100, 1, 0, 0, "T'chali's Voodoo Brewery Barker");

-- Зазывала пивоварни Дрона
SET @ENTRY := 24492;
SET @SPELL_DRINK := 42518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 22, 0, 100, 0, 101, 5000, 5000, 0, 11, @SPELL_DRINK, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Drohn's Distillery Barker - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"), 
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 30000, 45000, 180000, 240000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Drohn's Distillery Barker - Out of Combat - Yell Line 0 (random)"), 
(@ENTRY, 0, 2, 0, 38, 0, 100, 0, 3, 3, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drohn's Distillery Barker - On Data Set - Set Phase 1"), 
(@ENTRY, 0, 3, 0, 1, 1, 100, 0, 10000, 35000, 45000, 50000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Drohn's Distillery Barker - Out of Combat - Say Line 2 (random) (P1)"), 
(@ENTRY, 0, 4, 0, 1, 1, 100, 1, 3, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drohn's Distillery Barker - Out of Combat - Yell Line 1 (P1)"), 
(@ENTRY, 0, 5, 0, 52, 1, 100, 0, 1, @ENTRY, 0, 0, 50, 186471, 15000, 0, 0, 0, 0, 8, 0, 0, 0, 1191.014404, -4299.663574, 21.381546, 4.39, "Drohn's Distillery Barker - On Text Over - Summon Super Brew Stein Trap (P1)"), 
(@ENTRY, 0, 6, 0, 38, 0, 100, 0, 4, 4, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drohn's Distillery Barker - On Data Set - Set Phase 0"); -- Event is over, so set phase 0
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ENTRY, 0, 0, "Drohn's brew is the stuff legends are made of! Come taste the legend!", 12, 0, 100, 1, 0, 0, "Drohn's Distillery Barker"), 
(@ENTRY, 0, 1, "We drink for the Horde! Do you drink for the Horde? Come show us at Drohn's Distillery!", 12, 0, 100, 1, 0, 0, "Drohn's Distillery Barker"), 
(@ENTRY, 0, 2, "Hey you, the tall one... Want to put some hair on your chest? Drohn's Distillery can help you out!", 12, 0, 100, 1, 0, 0, "Drohn's Distillery Barker"), 
(@ENTRY, 0, 3, "Hey you! T'chali's Voodoo Brewers have got a brew that won't kill you! But they've also got a brew that might...", 12, 0, 100, 1, 0, 0, "Drohn's Distillery Barker"), 
(@ENTRY, 1, 0, "SOMEONE TRY THIS SUPER BREW!", 14, 0, 100, 0, 0, 0, "Drohn's Distillery Barker"), 
(@ENTRY, 2, 0, "Chug and chuck! Chug and chuck!", 12, 0, 100, 1, 0, 0, "Drohn's Distillery Barker"), 
(@ENTRY, 2, 1, "Down the free brew and pelt the Guzzlers with your mug!", 12, 0, 100, 1, 0, 0, "Drohn's Distillery Barker");
 
-- Add aura 'Brewfest - Dark Iron Attack - Keg Marker' to Thunderbrew/Barleybrew/Gordok/T'chalis's/Drohn's Festive Keg
DELETE FROM `creature_template_addon` WHERE `entry` IN (23702, 23700, 23706, 24373, 24372);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(23702, 0, 0, 0, 0, '42761'), (23700, 0, 0, 0, 0, '42761'), (23706, 0, 0, 0, 0, '42761'), 
(24373, 0, 0, 0, 0, '42761'), (24372, 0, 0, 0, 0, '42761');
 
-- Brewfest - Attack Keg can only target kegs
DELETE FROM `conditions` WHERE `SourceEntry` IN (42393) AND `ConditionValue2` IN (23702, 23700, 23706, 24373, 24372);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 42393, 0, 18, 1, 23702, 0, 0, '', "Spell Brewfest - Attack Keg can only be cast at Thunderbrew Festive Keg"), 
(13, 0, 42393, 0, 18, 1, 23700, 0, 0, '', "Spell Brewfest - Attack Keg can only be cast at Barleybrew Festive Keg"), 
(13, 0, 42393, 0, 18, 1, 23706, 0, 0, '', "Spell Brewfest - Attack Keg can only be cast at Gordok Festive Keg"), 
(13, 0, 42393, 0, 18, 1, 24373, 0, 0, '', "Spell Brewfest - Attack Keg can only be cast at T'chalis's Festive Keg"), 
(13, 0, 42393, 0, 18, 1, 24372, 0, 0, '', "Spell Brewfest - Attack Keg can only be cast at Drohn's Festive Keg");
 
-- Thunderbrew/Barleybrew/Gordok/T'chalis's/Drohn's Festive Keg
-- The unit_flags are taken from sniffs
SET @ENTRY1 := 23702; -- Праздничный бочонок громоварского
SET @ENTRY2 := 23700; -- Праздничный бочонок Ячменоваров
SET @ENTRY3 := 23706; -- Гордокский праздничный бочонок
SET @ENTRY4 := 24373; -- Праздничный бочонок вудуистского пива Т'чали
SET @ENTRY5 := 24372; -- Праздничный бочонок с винокурни Дрона
UPDATE `creature_template` SET `AIName`='SmartAI', `unit_flags`=`unit_flags`|256, `RegenHealth`=0 WHERE `entry` IN (@ENTRY1, @ENTRY2, @ENTRY3, @ENTRY4, @ENTRY5);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY1, @ENTRY2, @ENTRY3, @ENTRY4, @ENTRY5);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
-- Thunderbrew Festive Keg
(@ENTRY1, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Thunderbrew Festive Keg - Out of Combat - Set React State Passive"), 
(@ENTRY1, 0, 1, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 20, 186184, 0, 0, 0, 0, 0, 0, "Thunderbrew Festive Keg - On Death - Set Data Thunderbrew Festive Keg (OBJECT)"), 
(@ENTRY1, 0, 2, 0, 38, 0, 100, 0, 5, 5, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Thunderbrew Festive Keg - On Data Set - Forced Despawn"), 
(@ENTRY1, 0, 3, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 10, 10, 0, 0, 0, 0, 11, 23709, 3, 0, 0, 0, 0, 0, "Thunderbrew Festive Keg - On Death - Set Data Dark Iron Guzzler"), 
-- Barleybrew Festive Keg
(@ENTRY2, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Barleybrew Festive Keg - Out of Combat - Set React State Passive"), 
(@ENTRY2, 0, 1, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 20, 186189, 0, 0, 0, 0, 0, 0, "Barleybrew Festive Keg - On Death - Set Data Barleybrew Festive Keg (OBJECT)"), 
(@ENTRY2, 0, 2, 0, 38, 0, 100, 0, 5, 5, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Barleybrew Festive Keg - On Data Set - Forced Despawn"), 
(@ENTRY2, 0, 3, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 11, 11, 0, 0, 0, 0, 11, 23709, 3, 0, 0, 0, 0, 0, "Barleybrew Festive Keg - On Death - Set Data Dark Iron Guzzler"), 
-- Gordok Festive Keg
(@ENTRY3, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gordok Festive Keg - Out of Combat - Set React State Passive"), 
(@ENTRY3, 0, 1, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 20, 186185, 0, 0, 0, 0, 0, 0, "Gordok Festive Keg - On Death - Set Data Gordok Festive Keg (OBJECT)"), 
(@ENTRY3, 0, 2, 0, 38, 0, 100, 0, 5, 5, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gordok Festive Keg - On Data Set - Forced Despawn"), 
(@ENTRY3, 0, 3, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 12, 12, 0, 0, 0, 0, 11, 23709, 3, 0, 0, 0, 0, 0, "Gordok Festive Keg - On Death - Set Data Dark Iron Guzzler"), 
-- T'chalis's Festive Keg
(@ENTRY4, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "T'chalis's Festive Keg - Out of Combat - Set React State Passive"), 
(@ENTRY4, 0, 1, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 20, 186187, 0, 0, 0, 0, 0, 0, "T'chalis's Festive Keg - On Death - Set Data T'chalis's Festive Keg (OBJECT)"), 
(@ENTRY4, 0, 2, 0, 38, 0, 100, 0, 5, 5, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "T'chalis's Festive Keg - On Data Set - Forced Despawn"), 
(@ENTRY4, 0, 3, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 10, 10, 0, 0, 0, 0, 11, 23709, 3, 0, 0, 0, 0, 0, "T'chalis's Festive Keg - On Death - Set Data Dark Iron Guzzler"), 
-- Drohn's Festive Keg
(@ENTRY5, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drohn's Festive Keg - Out of Combat - Set React State Passive"), 
(@ENTRY5, 0, 1, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 20, 186186, 0, 0, 0, 0, 0, 0, "Drohn's Festive Keg - On Death - Set Data Drohn's Festive Keg (OBJECT)"), 
(@ENTRY5, 0, 2, 0, 38, 0, 100, 0, 5, 5, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drohn's Festive Keg - On Data Set - Forced Despawn"), 
(@ENTRY5, 0, 3, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 10, 10, 0, 0, 0, 0, 11, 23709, 3, 0, 0, 0, 0, 0, "Drohn's Festive Keg - On Death - Set Data Dark Iron Guzzler");
 
-- Festive Keg SAI (gameobjects)
-- Currently we can not despawn the objects through SAI, misses proper support. I'm still adding it because it might be of use for when this gets fixed
SET @ENTRY1 := 186184;
SET @ENTRY2 := 186189;
SET @ENTRY3 := 186185;
SET @ENTRY4 := 186187;
SET @ENTRY5 := 186186;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (@ENTRY1, @ENTRY2, @ENTRY3, @ENTRY4, @ENTRY5);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY1, @ENTRY2, @ENTRY3, @ENTRY4, @ENTRY5);
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY1, 1, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Thunderbrew Festive Keg - On Data Set - Despawn"), 
(@ENTRY2, 1, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Barleybrew Festive Keg - On Data Set - Despawn"), 
(@ENTRY3, 1, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gordok Festive Keg - On Data Set - Despawn"), 
(@ENTRY4, 1, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "T'chalis's Festive Keg - On Data Set - Despawn"), 
(@ENTRY5, 1, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drohn's Festive Keg - On Data Set - Despawn");
 
-- Гуляка Хмельного фестиваля
SET @ENTRY := 24484;
SET @SPELL_THROW_MUG := 50696;
SET @SPELL_CREATE_MUG := 42518;
SET @SPELL_TOAST := 41586;
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY, @ENTRY*100, @ENTRY*100+1); -- We are adding new lines so don't remove complete SAI
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 22, 0, 100, 0, 101, 5000, 5000, 0, 11, @SPELL_CREATE_MUG, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Brewfest Reveler - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"), 
(@ENTRY, 0, 1, 0, 22, 0, 100, 0, 34, 5000, 5000, 0, 11, @SPELL_TOAST, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Brewfest Reveler - Emote Receive 'Dance' - Cast Brewfest Toast"), 
(@ENTRY, 0, 2, 0, 1, 0, 100, 0, 4000, 11000, 15000, 20000, 10, 92, 1, 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brewfest Reveler - Out of Combat - Play Random Emote"), 
-- Dun Morogh
(@ENTRY, 0, 3, 0, 38, 0, 100, 0, 2, 2, 0, 0, 80, @ENTRY*100, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brewfest Reveler - On Data Set - Run Script"), 
(@ENTRY*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, @ENTRY, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, "Brewfest Reveler - On Script - Start WP"), 
(@ENTRY*100, 9, 1, 0, 0, 0, 100, 0, 1000, 5000, 5000, 5000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brewfest Reveler - On Script - Say Line 0 (random)"), 
(@ENTRY*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @SPELL_THROW_MUG, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brewfest Reveler - On Script - Cast Throw Mug"), 
(@ENTRY, 0, 4, 0, 58, 0, 100, 0, 3, @ENTRY, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brewfest Reveler - On WP 3 - Despawn"), 
-- Durotar
(@ENTRY, 0, 5, 0, 38, 0, 100, 0, 3, 3, 0, 0, 80, @ENTRY*100+1, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brewfest Reveler - On Data Set - Run Script"), 
(@ENTRY*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, @ENTRY*10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brewfest Reveler - On Script - Start WP"), 
(@ENTRY*100+1, 9, 1, 0, 0, 0, 100, 0, 1000, 5000, 5000, 5000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brewfest Reveler - On Script - Say Line 0 (random)"), 
(@ENTRY*100+1, 9, 2, 0, 0, 0, 100, 0, 1000, 3000, 3000, 3000, 11, @SPELL_THROW_MUG, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brewfest Reveler - On Script - Cast Throw Mug"), 
(@ENTRY, 0, 6, 0, 58, 0, 100, 0, 4, @ENTRY*10, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brewfest Reveler - On WP 4 - Despawn");
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ENTRY, 0, 0, "Dark Iron dwarves!", 12, 0, 100, 0, 0, 0, "Brewfest Reveler"), 
(@ENTRY, 0, 1, "Run! It's the Dark Iron dwarves!", 12, 0, 100, 0, 0, 0, "Brewfest Reveler"), 
(@ENTRY, 0, 2, "They're after the beer!", 12, 0, 100, 0, 0, 0, "Brewfest Reveler"), 
(@ENTRY, 0, 3, "Someone has to save the beer!", 12, 0, 100, 0, 0, 0, "Brewfest Reveler"), 
(@ENTRY, 0, 4, "If you value your beer, run for it!", 12, 0, 100, 0, 0, 0, "Brewfest Reveler");
-- Waypoints
DELETE FROM `waypoints` WHERE `entry` IN (@ENTRY, @ENTRY*10);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
-- Dun Morogh
(@ENTRY, 1, -5184.680176, -562.372009, 397.260010, 'Brewfest Reveler'), 
(@ENTRY, 2, -5192.152832, -547.358459, 397.177094, 'Brewfest Reveler'), 
(@ENTRY, 3, -5198.825684, -530.586243, 392.940155, 'Brewfest Reveler'), 
-- Durotar
(@ENTRY*10, 1, 1209.775879, -4342.093750, 21.295063, 'Brewfest Reveler'), 
(@ENTRY*10, 2, 1203.770874, -4356.925781, 21.967909, 'Brewfest Reveler'), 
(@ENTRY*10, 3, 1202.042725, -4370.892578, 24.852894, 'Brewfest Reveler'), 
(@ENTRY*10, 4, 1199.489868, -4389.286621, 23.865566, 'Brewfest Reveler');

-- Пьяный гуляка Хмельного фестиваля
SET @ENTRY := 23698;
SET @GUID_1 := 84667; -- guid c ytdb
SET @GUID_2 := 84714; -- guid c ytdb
SET @SPELL_VOMIT := 67468;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`='43905' WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@GUID_1, -@GUID_2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-@GUID_1, 0, 0, 0, 1, 0, 100, 0, 10000, 45000, 180000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drunken Brewfest Reveler - Out of Combat - Say Line 0 (random)"), 
(-@GUID_1, 0, 1, 0, 1, 0, 100, 0, 10000, 45000, 180000, 240000, 11, @SPELL_VOMIT, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drunken Brewfest Reveler - Out of Combat - Cast Drunken Vomit"), 
(-@GUID_2, 0, 0, 0, 1, 0, 100, 0, 10000, 45000, 180000, 240000, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drunken Brewfest Reveler - Out of Combat - Say Line 1 (random)"), 
(-@GUID_2, 0, 1, 0, 1, 0, 100, 0, 10000, 45000, 180000, 240000, 11, @SPELL_VOMIT, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drunken Brewfest Reveler - Out of Combat - Cast Drunken Vomit");
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `TEXT`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Alliance
(@ENTRY, 0, 0, "Uh oh...", 12, 0, 100, 0, 0, 0, "Drunken Brewfest Reveler"), 
(@ENTRY, 0, 1, "Good times! <hic>", 12, 0, 100, 0, 0, 0, "Drunken Brewfest Reveler"), 
(@ENTRY, 0, 2, "What's all the fuss about here?", 12, 0, 100, 0, 0, 0, "Drunken Brewfest Reveler"), 
(@ENTRY, 0, 3, "The besht part about drinking is pretending to be drunk... I'm jusht pretending guys.", 12, 0, 100, 0, 0, 0, "Drunken Brewfest Reveler"), 
(@ENTRY, 0, 4, "Hey fellas! How's it going?", 12, 0, 100, 0, 0, 0, "Drunken Brewfest Reveler"), 
(@ENTRY, 0, 5, "Hey! Anyone shee that cute blond dwarf? I shwear they were jusht here...", 12, 0, 100, 0, 0, 0, "Drunken Brewfest Reveler"), 
(@ENTRY, 0, 6, "Hey! Lishten up! I've got... I have something important to talk about! Shee... Wait... What wash I shaying? Something aboutsh boats and floating... Yeah! Sho don't float on a boat... Thank you...", 12, 0, 100, 0, 0, 0, "Drunken Brewfest Reveler"), 
-- Horde
(@ENTRY, 1, 0, "Uh oh...", 12, 0, 100, 0, 0, 0, "Drunken Brewfest Reveler"), 
(@ENTRY, 1, 1, "Good times! <hic>", 12, 0, 100, 0, 0, 0, "Drunken Brewfest Reveler"), 
(@ENTRY, 1, 2, "What's all the fuss about here?", 12, 0, 100, 0, 0, 0, "Drunken Brewfest Reveler"), 
(@ENTRY, 1, 3, "The besht part about drinking is pretending to be drunk... I'm jusht pretending guys.", 12, 0, 100, 0, 0, 0, "Drunken Brewfest Reveler"), 
(@ENTRY, 1, 4, "You guys have gotta try thish...", 12, 0, 100, 0, 0, 0, "Drunken Brewfest Reveler"), 
(@ENTRY, 1, 5, "Hey! You for the Horde? <hic> I'm for the Horde!", 12, 0, 100, 0, 0, 0, "Drunken Brewfest Reveler");

-- Пивной пузырь
SET @ENTRY := 27882;
SET @SPELL_GROW := 49828;
UPDATE `creature_template` SET `AIName`='SmartAI', `unit_flags`=33554432 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 3000, 7000, 0, 0, 11, @SPELL_GROW, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brew Bubble - Out of Combat - Cast Bubble Build Up"), 
(@ENTRY, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 89, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brew Bubble - Just Summoned - Set Random Movement");

-- [Q] [A/H] Пей до дна!
SET @ENTRY := 24108;
SET @SPELL_THROW_MUG := 42300;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, @SPELL_THROW_MUG, 0, 0, 0, 33, @ENTRY, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Self-Turning and Oscillating Utility Target - On Spellhit - Quest Credit');
-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=42300;
-- INSERT INTO `conditions` VALUES
-- (13, 0, 42300, 0, 18, @ENTRY, 0, 0, 0, '', 'Spell Brewfest - Throw Mug targets Self-Turning and Oscillating Utility Target');

-- Q 12020, 12192 - Однажды, напившись в...
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `entry`=12020;
DELETE FROM `gameobject_questrelation` WHERE `quest` IN (12020, 12192);
INSERT INTO `gameobject_questrelation` (`id`, `quest`) VALUES
(189989, 12020), -- Alliance
(189990, 12192); -- Horde

-- summoned
DELETE FROM `gameobject` WHERE `id` IN (186881, 186478);
-- [DND] Brewfest Target Dummy Move To Target
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=24109; 

-- [Q] Кто сказал "сувениры"? 
DELETE FROM `creature_questrelation` WHERE `quest` IN (11321, 11413);
DELETE FROM `creature_involvedrelation` WHERE `quest` IN (11321, 11413);
-- [Q] А не будет ли сувенирчика в нынешнем году?
DELETE FROM `creature_questrelation` WHERE `quest` IN (12193, 12194);
DELETE FROM `creature_involvedrelation` WHERE `quest` IN (12193, 12194);

-- [Q] [A/H] Новый подарок к новому году.
-- 2010-09-20 (Обновление 3.3.5)
-- Requires you to have completed the quest Now This is Ram Racing... Almost. in order for this quest to become available.
-- http://ru.wowhead.com/quest=13931#english-comments
DELETE FROM `creature_involvedrelation` WHERE `id` IN (24495, 23710) AND `quest` IN (13931, 13932);
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES
(24495, 13931), -- Horde
(23710, 13932); -- Alliance
DELETE FROM `creature_questrelation` WHERE `id` IN (24510, 24468) AND `quest` IN (13931, 13932);
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES
(24510, 13931), -- Horde
(24468, 13932); -- Alliance
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry` IN (24468, 24495, 23710, 24510, 24468);

-- [Q] [A/H] Новый подарок к новому году - removed in 2.4.3
-- DELETE FROM `creature_involvedrelation` WHERE `id` IN (23710, 24495) AND `quest` IN (11321, 11413);
-- DELETE FROM `creature_questrelation` WHERE `id` IN (23710, 24495) AND `quest` IN (11321, 11413);

-- [Q] [A/H] - Клуб "Пиво месяца"
-- Приходит по почте, пока оставил, по комментариям на  3.3.5a можно сдать квест
UPDATE `item_template` SET `StartQuest`=12278 WHERE `entry` = 37571;
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12278;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (27478, 12278);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`=27478;

UPDATE `item_template` SET `StartQuest`=12421 WHERE `entry` = 37737;
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12421;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (27489, 12421);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`=27489;
 

-- Misc.
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|256 WHERE `entry`=23706; -- Gordok Festive Keg
UPDATE `creature_model_info` SET `bounding_radius`=0.9, `combat_reach`=1.8, `gender`=2 WHERE `modelid`=24860; -- Gordok Festive Keg
-- Inmun
UPDATE `creature_template` SET `mechanic_immune_mask` = `mechanic_immune_mask`|1|2|8|16|32|64|128|256|512|1024|2048|4096|8192|65536|131072|524288|4194304|8388608|33554432|67108864|536870912 WHERE `entry` IN (23872, 26822, 26764);
UPDATE `quest_template` SET `SpecialFlags`=9 WHERE `entry`=25483;
UPDATE `creature_template` SET `npcflag`=3 WHERE `entry`=23872;

-- Терминал буровой установки
SET @ENTRY := 188498;
SET @GUID := 2710571; -- guid заменить для ytdb
DELETE FROM `gameobject` WHERE `id` = @ENTRY;
DELETE FROM `game_event_gameobject` WHERE `guid` = @GUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@GUID, @ENTRY, 230, 1, 1, 1133.59, -462.347, -103.659, 5.75403, 0, 0, 0.261501, -0.965203, 300, 0, 1);
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(26, @GUID);

-- Brewfest - Dark Iron Knockback
DELETE FROM `conditions` WHERE `SourceEntry`=42299 AND `ConditionValue2`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 42299, 0, 18, 1, 0, 0, 0, '', "Spell Brewfest - Dark Iron Knockback can only be cast at players");
-- Brewfest Chick Chucks Mug should also add an Complimentary Brewfest Sampler
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=42535 AND `spell_effect`=42518;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(42535, 42518, 1, 'Brewfest Chick Chucks Mug should also add an Complimentary Brewfest Sampler');
 
-- Limit Target
-- Обезвреживание Зловещего Варева
-- Заказ второй кружки
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (47344, 47310);
INSERT INTO `conditions` VALUES
(13, 0, 47310, 0, 18, 1, 0, 0, 0, '', NULL), -- Cast Disarm AOE
(13, 0, 47344, 0, 18, 1, 26764, 0, 0, '', NULL), 
(13, 0, 47344, 0, 18, 1, 26822, 0, 0, '', NULL);
-- Spell scripts - Заказ второй кружки
DELETE FROM `spell_scripts` WHERE `id`=47344;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`)
VALUES
(47344, 0, 0, 15, 47339, 3, 0, 0, 0, 0, 0); -- cast back "Send Second Mug" on "Request Second Mug" hit
-- Condition for spell
-- Brewfest - Create Complimentary Brewfest Sampler
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=42518;
-- INSERT INTO `conditions` VALUES
-- (13, 0, 42518, 0, 18, 1, 0, 0, 0, '', 'Spell Create Complimentary Brewfest Sampler targets players'), 
-- (13, 0, 42518, 0, 26, 33096, 0, 0, 0, '', 'Spell Create Complimentary Brewfest Sampler targets players');
-- Spell Бульк!
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=42436;
-- INSERT INTO `conditions` VALUES
-- (13, 0, 42436, 0, 18, 1, 0, 0, 0, '', 'Spell Drink! targets player');
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 42436;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(42436, 47173, 0, 'Brewfest Sampler');

-- Spell Auras 
-- Темное пиво официантки (алкоголь)
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 47371;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(47371, -47376, 1, 'Remove Visual Buff'), 
(47371, -47331, 1, 'Remove Has Brew Aura');
-- Wild Winter Pilsner
-- Spell Weak Alcohol (42256) should make the ground shake
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-50098, 42256) AND `spell_effect` IN (51655, 50099);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-50098, 50099, 0, 'Weak Alcohol will now also make the ground shake on removal'), 
(42256, 51655, 1, 'Weak Alcohol will now also add an Empty Brew Bottle to the player');
-- Blackrock Lager
-- Spell Weak Alcohol (42257) should make you puke spit on aura removal
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-49738, 42257) AND `spell_effect` IN (51655, 49737);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-49738, 49737, 0, 'Weak Alcohol will now also make the player spit fire on removal'), 
(42257, 51655, 1, 'Weak Alcohol will now also add an Empty Brew Bottle to the player');
-- Metok's Bubble Bock
-- Spell Weak Alcohol (43961) should make you summon a bubble
-- www.youtube.com/watch?v=FMFkuxHcuMg&fmt=22
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (43961) AND `spell_effect` IN (50072, 51655);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(43961, 50072, 1, 'Weak Alcohol will now also summon a bubble'), 
(43961, 51655, 1, 'Weak Alcohol will now also add an Empty Brew Bottle to the player');
-- Izzard's Ever Flavor
-- Spell Weak Alcohol (42255) should make you puke on aura removal
-- www.youtube.com/watch?v=ZsP6UqOZpHU&fmt=22
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-49864, 42255) AND `spell_effect` IN (51655, 49860);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-49864, 49860, 0, 'Weak Alcohol will now also make the player puke on removal'), 
(42255, 51655, 1, 'Weak Alcohol will now also add an Empty Brew Bottle to the player');
-- Stranglethorn Brew
-- Needs core script I am afraid
-- Spell Weak Alcohol (43959) should make you summon a few jungle gnomes???
-- www.youtube.com/watch?v=Ek0BtY-JBoM
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (43959) AND `spell_effect` IN (51655);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(43959, 51655, 1, 'Weak Alcohol will now also add an Empty Brew Bottle to the player');
-- Binary Brew
-- Spell Weak Alcohol (42259) should make you summon a bubble
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (42259) AND `spell_effect` IN (50243, 51655);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(42259, 50243, 1, 'Weak Alcohol will now also cast Teach Language'), 
(42259, 51655, 1, 'Weak Alcohol will now also add an Empty Brew Bottle to the player');
-- Bartlett's Bitter Brew
-- Spell Weak Alcohol (42258) should make you puke on aura removal
-- www.youtube.com/watch?v=ZsP6UqOZpHU&fmt=22
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-49869, 42258) AND `spell_effect` IN (51655, 49867);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-49869, 49867, 0, 'Weak Alcohol will now also make the player puke on removal'), 
(42258, 51655, 1, 'Weak Alcohol will now also add an Empty Brew Bottle to the player');

-- Dark Iron Guzzler
-- We are setting AIName because some people applied the SAI for this NPC :)
UPDATE `creature_template` SET `equipment_id`=2477, `unit_flags`=33024 WHERE `entry`=23709;
-- Text
DELETE FROM `creature_text` WHERE `entry`=23709;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `TEXT`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(23709, 0, 0, "Did someone say 'Free Brew'?", 12, 0, 20, 0, 0, 0, "Dark Iron Guzzler"), 
(23709, 0, 1, "DRINK! BRAWL! DRINK! BRAWL!", 12, 0, 100, 0, 0, 0, "Dark Iron Guzzler"), 
(23709, 0, 2, "Drink it all boys!", 12, 0, 50, 0, 0, 0, "Dark Iron Guzzler"), 
(23709, 0, 3, "It's not a party without some crashers!", 12, 0, 30, 0, 0, 0, "Dark Iron Guzzler");
-- Add Dark Iron Guzzler's equipment template (taken from sniff)
DELETE FROM `creature_equip_template` WHERE `entry`=2477 AND `itemEntry1`=33125;
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(2477, 33125, 0, 0);
-- Add aura 'Holiday - Brewfest - Dark Iron Knockback Target Test' to Dark Iron Guzzler
DELETE FROM `creature_template_addon` WHERE `entry`=23709;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(23709, 0, 0, 0, 0, '42676');
-- Drunken Master & Dark Iron Retreat
-- Holiday - Brewfest - Dark Iron Knock-down Power-up
DELETE FROM `conditions` WHERE `SourceEntry` IN (42695, 42341) AND `ConditionValue2` IN (23709);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 42695, 0, 18, 1, 23709, 0, 0, '', "Spell Holiday - Brewfest - Dark Iron Knock-down Power-up can only be cast at Dark Iron Guzzler"), 
(13, 0, 42341, 0, 18, 1, 23709, 0, 0, '', "Spell Dark Iron Retreat can only be cast at Dark Iron Guzzler");
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=42794;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 42794, 0, 18, 1, 23709, 0, 0, '', "Spell Holiday - Brewfest - Random Mug Fling can only be cast at Dark Iron Guzzler");


-- Бликс Чиништукс <Выдача призов>
-- http://ru.wowhead.com/npc=24495#english-comments
SET @ENTRY := 24495;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 22, 0, 100, 0, 101, 5000, 5000, 0, 11, @SPELL_DRINK, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Blix Fixwidget - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"), 
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 30000, 45000, 180000, 240000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Blix Fixwidget - Out of Combat - Say Line 0 (random)");
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ENTRY, 0, 0, "Whoah! Walk by again girl!", 12, 0, 100, 1, 0, 0, "Blix Fixwidget"), 
(@ENTRY, 0, 1, "Hey! Sweet cheeks, over here!", 12, 0, 100, 1, 0, 0, "Blix Fixwidget"), 
(@ENTRY, 0, 2, "Hey, hey sweet thing! Looking good!", 12, 0, 100, 1, 0, 0, "Blix Fixwidget"), 
(@ENTRY, 0, 3, "Hey, hey! Nice build you got there honey!", 12, 0, 100, 1, 0, 0, "Blix Fixwidget"), 
(@ENTRY, 0, 4, "Yo! Big lady! You think you're big enough to handle me?", 12, 0, 100, 1, 0, 0, "Blix Fixwidget");




-- ScriptNames
UPDATE `gameobject_template` SET `ScriptName` = 'go_mole_machine_console' WHERE `entry` = 188498;
UPDATE `item_template` SET `ScriptName` = 'item_brewfest_ChugAndChuck' WHERE `entry` = 33096;
UPDATE `item_template` SET `ScriptName` = 'item_brewfest_ram_reins' WHERE `entry` = 33306;
UPDATE `creature_template` SET `ScriptName` = 'npc_coren_direbrew' WHERE `entry` = 23872;
UPDATE `creature_template` SET `ScriptName` = 'npc_brewmaiden' WHERE `entry` IN (26822, 26764);
UPDATE `creature_template` SET `ScriptName`='npc_brewfest_apple_trigger' WHERE `entry`=24337;
UPDATE `creature_template` SET `ScriptName`='npc_brewfest_keg_thrower' WHERE `entry`=24364;
UPDATE `creature_template` SET `ScriptName`='npc_brewfest_keg_thrower' WHERE `entry`=24527;
UPDATE `creature_template` SET `ScriptName`='npc_brewfest_keg_receiver' WHERE `entry`=24468;
UPDATE `creature_template` SET `ScriptName`='npc_brewfest_keg_receiver' WHERE `entry`=24510;
UPDATE `creature_template` SET `ScriptName`='npc_brewfest_ram_master' WHERE `entry`=23558;
UPDATE `creature_template` SET `ScriptName`='npc_brewfest_ram_master' WHERE `entry`=24497;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_brewfest_trigger' WHERE `entry` in (24202, 24203, 24204, 24205);
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_dark_iron_guzzler' WHERE `entry`=23709;

-- Holiday - Brewfest - Dark Iron - Get Region - Spawn
DELETE FROM `spell_script_names` WHERE `spell_id`=43668;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(43668, 'spell_gen_dark_iron_dwarf_spawn');
-- Holiday - Brewfest - Dark Iron Knockback Target Test
DELETE FROM `spell_script_names` WHERE `spell_id`=42674;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(42674, 'spell_gen_dark_iron_knockback_test');

DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (24202, 24203, 24204, 24205);

-- Insert missing object template for spell Drunken Master's - it's a trap and these do not come from sniffs, so WDBVerified on 1
DELETE FROM `gameobject_template` WHERE `entry`=186471;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES
(186471, 6, 6371, 'Super Brew Stein', '', '', '', 35, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 8, 42696, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 1);
-- Insert missing triggered objectsummons - they dissapear through another object which makes the despawn animation
DELETE FROM `gameobject_template` WHERE `entry` IN (202401, 186462);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES
(202401, 1, 7510, 'Dark Iron Mole Machine', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 95, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 1),
(186462, 1, 7510, 'Dark Iron Mole Machine', '', '', '', 0, 0, 0.6, 0, 0, 0, 0, 0, 0, 1, 95, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 1);

-- Spawn [DND] Brewfest Dark Iron Event Generator and Dark Iron Herald
SET @GUID_1 := 86870;  -- guid с ytdb
SET @GUID_2 := 86952;  -- guid с ytdb
SET @GUID_3 := 496941; -- guid заменить для ytdb
SET @GUID_4 := 496942; -- guid заменить для ytdb
SET @GUID_5 := 84635;  -- guid c ytdb
SET @GUID_6 := 84709;  -- guid c ytdb
DELETE FROM `creature` WHERE `id` IN (23703, 24536) AND `guid` IN (@GUID_1, @GUID_4, @GUID_3, @GUID_2);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@GUID_1, 23703, 0, 1, 1, 0, 0, -5152.3, -603.529, 398.356, 2.50732, 300, 0, 0, 37800, 0, 0, 0, 0, 0), 
(@GUID_2, 23703, 1, 1, 1, 0, 0, 1197.6, -4293.571, 21.243, 5.20232, 300, 0, 0, 37800, 0, 0, 0, 0, 0), 
(@GUID_3, 24536, 0, 1, 1, 0, 0, -5152.3, -603.529, 398.356, 2.50732, 300, 0, 0, 37800, 0, 0, 0, 0, 0), 
(@GUID_4, 24536, 1, 1, 1, 0, 0, 1197.6, -4293.571, 21.243, 5.20232, 300, 0, 0, 37800, 0, 0, 0, 0, 0);
DELETE FROM `creature` WHERE `id`=23685;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID_5, 23685, 0, 1, 1, 22628, 0, -5136.68, -586.151, 397.26, 3.57792, 600, 0, 0, 2215, 0, 0, 0, 0, 0),
(@GUID_6, 23685, 1, 1, 1, 22628, 0, 1216.6, -4284.27, 21.2903, 3.78736, 600, 0, 0, 2215, 0, 0, 0, 0, 0);
-- Make the Event Generator spawns only spawn if Brewfest is active
DELETE FROM `game_event_creature` WHERE `eventEntry`=26 AND `guid` IN 
(@GUID_1, @GUID_2, @GUID_3, @GUID_4, @GUID_5, @GUID_6);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(26, @GUID_1), (26, @GUID_2), (26, @GUID_3), (26, @GUID_4), (26, @GUID_5), (26, @GUID_6);
 
-- [DND] Brewfest Dark Iron Event Generator SAI
SET @ENTRY := 23703;
SET @SPELL_RETREAT := 42341;
SET @SPELL_MOLE_MACHINE_SPAWN := 73074;
UPDATE `creature_template` SET `AIName`='SmartAI', `flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@GUID_1, -@GUID_2, @ENTRY*100, @ENTRY*100+1, @ENTRY*100+2, @ENTRY*100+3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
-- DUN MOROGH
(-@GUID_1, 0, 0, 1, 1, 0, 100, 0, 1800000, 1800000, 1800000, 1800000, 80, @ENTRY*100, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - Out of Combat - Run Script"), 
(-@GUID_1, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24536, 100, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - Out of Combat - Set Data Dark Iron Herald"), 
(-@GUID_1, 0, 2, 0, 38, 0, 100, 0, 5, 5, 0, 0, 80, @ENTRY*100+3, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Data Set - Run Script"), 
(@ENTRY*100, 9, 1, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5168.79, -597.261, 398.101, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), -- Time this to give the Brewfest Revelers some time to run away
(@ENTRY*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5154.99, -589.22, 397.346, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5168.34, -585.515, 397.688, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5160.86, -606.37, 398.063, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5163.08, -592.054, 398.022, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5160.24, -579.148, 397.18, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5172.88, -576.9, 397.339, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5180.1, -583.465, 397.775, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5176.84, -592.674, 397.622, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5172.06, -606.161, 397.352, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5162.5, -614.447, 397.741, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5153.05, -618.085, 398.125, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5148.92, -607.028, 398.537, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5155.28, -598.89, 398.092, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5146.97, -591.708, 397.372, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5136.8, -598.046, 397.426, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 17, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5162.125000, -599.126953, 398.169250, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 18, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5155.227051, -611.064087, 398.384796, 5.58, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 19, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5172.685547, -617.705200, 397.190582, 0.80, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 20, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5165.557129, -602.531067, 397.959229, 2.48, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 21, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5162.540039, -596.897278, 398.152252, 5.58, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 22, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5171.027832, -590.153503, 397.964874, 0.80, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 23, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5177.630371, -600.892029, 397.344421, 2.48, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 24, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5175.105957, -585.409302, 397.801575, 5.58, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 25, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5160.901367, -585.973755, 397.494049, 0.80, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 26, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5149.727051, -598.186523, 398.000702, 2.48, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 27, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5140.413574, -606.157715, 398.110840, 0.80, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 28, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5148.443359, -613.181458, 398.464478, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 29, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5139.434570, -612.224487, 398.017578, 5.58, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 30, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5160.227051, -622.226868, 397.487183, 2.53, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 31, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5165.484863, -608.644226, 397.621552, 3.85, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 32, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5154.422852, -605.168152, 398.364655, 1.23, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 33, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5156.091309, -594.039612, 397.730194, 0.32, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 34, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5151.526855, -593.310730, 397.529968, 0.32, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 35, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5143.669922, -603.026917, 398.192719, 0.80, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 36, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5142.348633, -595.296265, 397.526245, 3.32, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 37, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5154.107910, -582.890503, 397.179108, 6.32, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 38, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5166.127930, -578.236206, 397.194489, 4.12, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 39, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5182.114746, -589.290283, 397.433838, 3.21, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 40, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5173.672363, -598.698364, 397.764160, 5.21, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 41, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5170.576660, -612.272156, 397.254028, 1.12, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 42, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5157.810059, -615.534058, 398.061340, 3.21, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 43, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5170.45, -619.995, 397.201, 5.03293, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 44, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5178.76, -596.961, 397.377, 1.7539, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 45, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5156.98, -580.003, 397.177, 0.120272, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 46, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5179.38, -586.717, 397.709, 4.49259, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 47, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5165.36, -587.727, 397.835, 1.67301, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 48, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5153.73, -615.453, 398.279, 0.856196, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 49, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5152.15, -595.603, 397.77, 4.901, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 50, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5162.17, -574.909, 397.177, 5.99506, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 51, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5168.06, -574.334, 397.179, 4.72586, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 52, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5175.6, -580.338, 397.672, 1.99189, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 53, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5173.89, -589.037, 397.868, 2.61942, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 54, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5174.16, -610.4, 397.19, 1.88822, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 55, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5168.59, -608.303, 397.421, 3.79124, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 56, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5139.81, -601.143, 397.845, 5.16019, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 57, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5148.49, -602.523, 398.322, 5.16019, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 58, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5150.64, -587.595, 397.217, 5.8317, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 59, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5164.38, -582.486, 397.347, 5.68012, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 60, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5170.38, -581.177, 397.41, 1.41776, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 61, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5172.32, -594.611, 397.974, 1.78454, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100, 9, 62, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23702, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5159.85, -632.055, 397.179, 1.46772, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon Thunderbrew Festive Keg"), 
(@ENTRY*100, 9, 63, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23706, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5146.283691, -576.265930, 397.176514, 0.09009, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon Gordok Festive Keg"), 
(@ENTRY*100, 9, 64, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23700, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -5186.539551, -599.753662, 397.176453, 0.024872, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon Barleybrew Festive Keg"), 
(@ENTRY*100, 9, 66, 0, 0, 0, 100, 0, 59000, 79000, 90000, 90000, 45, 2, 2, 0, 0, 0, 0, 11, 23685, 50, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Gordok Brew Barker"), 
(@ENTRY*100, 9, 67, 0, 0, 0, 100, 0, 10000, 29000, 90000, 90000, 45, 3, 3, 0, 0, 0, 0, 11, 23683, 50, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Maeve Barleybrew"), 
(@ENTRY*100, 9, 68, 0, 0, 0, 100, 0, 3000, 11000, 90000, 90000, 45, 4, 4, 0, 0, 0, 0, 11, 23684, 50, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Ita Thunderbrew"), 
-- DUROTAR
(-@GUID_2, 0, 0, 1, 1, 0, 100, 0, 1800000, 1800000, 1800000, 1800000, 80, @ENTRY*100+1, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - Out of Combat - Run Script"), 
(-@GUID_2, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24536, 100, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - Out of Combat - Set Data Dark Iron Herald"), 
(-@GUID_2, 0, 2, 0, 38, 0, 100, 0, 5, 5, 0, 0, 80, @ENTRY*100+2, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Data Set - Run Script"), 
(@ENTRY*100+1, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1204.37, -4279.81, 21.1922, 3.84123, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1198.54, -4276.24, 21.1922, 0.617165, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1204.52, -4282.65, 21.1922, 3.73127, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1195.59, -4282.27, 21.1928, 0.42867, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1190.5, -4279.52, 21.1916, 5.64764, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1186.5, -4281.45, 21.1916, 0.526844, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1182.72, -4285.52, 21.1916, 0.994156, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1198.15, -4286.48, 21.197, 3.531, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1191.91, -4286.18, 21.194, 3.32287, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1188.62, -4289.83, 21.1958, 4.45777, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1182.62, -4292.68, 21.1755, 4.34388, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1185.53, -4297.08, 21.2927, 0.456159, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1189.84, -4296.02, 21.3273, 6.2524, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1194.04, -4291.03, 21.2161, 1.28475, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1196.33, -4295.06, 21.2993, 6.05997, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 17, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1200.13, -4290.59, 21.2003, 0.797805, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 18, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1203.6, -4287.35, 21.1943, 1.36329, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 19, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1199.9, -4281.51, 21.1974, 3.80588, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 20, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1187.18, -4285.77, 21.1921, 3.69592, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 21, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1185.34, -4289.22, 21.1921, 4.52844, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 22, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1190.7, -4293.48, 21.258, 6.11102, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 23, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1200.36, -4293.36, 21.2189, 0.322628, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 24, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1204.04, -4291.89, 21.1951, 0.683911, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 25, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1207.19, -4286.44, 21.192, 1.35935, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 26, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1210.33, -4284.73, 21.192, 5.65548, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 27, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1212.97, -4288.85, 21.192, 4.25748, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 28, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1208.33, -4291.2, 21.192, 3.49957, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 29, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1206.46, -4294.69, 21.1925, 4.63054, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 30, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1208.4, -4297.3, 21.1929, 0.915605, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 31, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1213.24, -4292.98, 21.1929, 0.518979, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 32, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1215.26, -4296.66, 21.1929, 4.1004, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 33, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1212.44, -4299.5, 21.1929, 3.6645, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 34, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1206.24, -4300.01, 21.1978, 2.72595, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 35, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1199.34, -4298.13, 21.377, 3.02047, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 36, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1197.71, -4300.08, 21.4586, 4.93684, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 37, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1203.39, -4297.49, 21.2196, 2.00338, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 38, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1201.1, -4301.55, 21.3483, 2.99691, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 39, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1196.24, -4303.98, 21.2509, 2.66311, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 40, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1193.57, -4298.09, 21.4725, 2.84768, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 41, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1189.9, -4300.33, 21.3319, 3.9708, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 42, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1192.37, -4303.41, 21.2629, 5.4395, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 43, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1207.39, -4303.19, 21.3475, 0.350117, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 44, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1213.96, -4302.97, 21.192, 5.67905, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 45, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1214.59, -4305.26, 21.192, 4.47739, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 46, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1210.72, -4304.51, 21.3555, 2.41179, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 47, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1209.12, -4308.69, 21.243, 2.71417, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 48, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1203.82, -4303.28, 21.2771, 2.12512, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 49, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1204.53, -4306.97, 21.2342, 3.62523, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 50, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1204.76, -4310.99, 21.252, 3.72341, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 51, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1201.8, -4309.15, 21.2576, 2.2233, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 52, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1200.39, -4305.57, 21.2246, 1.91307, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 53, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1197.17, -4310.19, 21.292, 3.37391, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 54, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1195.19, -4307.9, 21.2921, 1.79918, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 55, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1192.68, -4309.06, 21.2945, 2.078, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 56, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1189.37, -4304.97, 21.2507, 2.60422, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 57, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1185.69, -4301.03, 21.2623, 2.2233, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 58, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1194.77, -4300.84, 21.3994, 0.892044, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 59, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1197.76, -4291.57, 21.213, 1.19442, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 60, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1194.9, -4285.23, 21.196, 0.703549, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 61, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23894, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1201.07, -4285.3, 21.1986, 6.13458, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), 
(@ENTRY*100+1, 9, 62, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 24373, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1182.845, -4273.276, 21.27497, 1.46772, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon T'chali's Voodoo Brew Festive Keg"), 
(@ENTRY*100+1, 9, 63, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 23706, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1222.903, -4296.746, 21.27534, 0.09009, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon Gordok Festive Keg"), 
(@ENTRY*100+1, 9, 64, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 24372, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 1184.316, -4314.621, 21.37921, 0.024872, "[DND] Brewfest Dark Iron Event Generator - On Script - Summon Drohn's Distillery Festive Keg"), 
(@ENTRY*100+1, 9, 66, 0, 0, 0, 100, 0, 59000, 79000, 90000, 90000, 45, 2, 2, 0, 0, 0, 0, 11, 23685, 70, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Gordok Brew Barker"), 
(@ENTRY*100+1, 9, 67, 0, 0, 0, 100, 0, 10000, 29000, 90000, 90000, 45, 3, 3, 0, 0, 0, 0, 11, 24492, 70, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Drohn's Distillery Barker"), 
(@ENTRY*100+1, 9, 68, 0, 0, 0, 100, 0, 3000, 11000, 90000, 90000, 45, 4, 4, 0, 0, 0, 0, 11, 24493, 70, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Set Data T'chalis's Voodoo Brewewry Barket"), 
(@ENTRY*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @SPELL_RETREAT, 0, 0, 0, 0, 0, 11, 23709, 100, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Cast Brewfest Retreat"), 
(@ENTRY*100+2, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @SPELL_MOLE_MACHINE_SPAWN, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Cast Brewfest Retreat"), 
(@ENTRY*100+2, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 11, 24493, 100, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Set Data T'chali's Voodoo Brewery Barker"), 
(@ENTRY*100+2, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 11, 24492, 100, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Drohn's Distillery Barker"), 
(@ENTRY*100+2, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 10, @GUID_5, 23685, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Gordok Brew Barker"), 
(@ENTRY*100+2, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Despawn"), 
(@ENTRY*100+3, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @SPELL_RETREAT, 0, 0, 0, 0, 0, 11, 23709, 100, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Cast Brewfest Retreat"), 
(@ENTRY*100+3, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @SPELL_MOLE_MACHINE_SPAWN, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Cast Brewfest Retreat"), 
(@ENTRY*100+3, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 11, 23683, 100, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Maeve Barleybrew"), 
(@ENTRY*100+3, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 11, 23684, 100, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Ita Thunderbrew"), 
(@ENTRY*100+3, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 10, @GUID_6, 23685, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Gordok Brew Barker"), 
(@ENTRY*100+3, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Event Generator - On Script - Despawn");

-- Зазывала из клана Гордок
SET @ENTRY := 23685;
SET @SPELL_DRINK := 42518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@GUID_5, -@GUID_6, @ENTRY);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
-- Dun Morogh version
(-@GUID_5, 0, 0, 0, 22, 0, 100, 0, 101, 5000, 5000, 0, 11, @SPELL_DRINK, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Gordok Brew Barker - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"), 
(-@GUID_5, 0, 1, 0, 1, 0, 100, 0, 30000, 45000, 180000, 240000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Gordok Brew Barker - Out of Combat - Yell Line 0 (random)"), 
(-@GUID_5, 0, 2, 0, 38, 0, 100, 0, 3, 3, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gordok Brew Barker - On Data Set - Set Phase 1"), 
(-@GUID_5, 0, 3, 0, 1, 1, 100, 0, 10000, 35000, 45000, 50000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Gordok Brew Barker - Out of Combat - Say Line 2 (random) (P1)"), 
(-@GUID_5, 0, 4, 0, 1, 1, 100, 1, 3, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gordok Brew Barker - Out of Combat - Yell Line 1 (P1)"), 
(-@GUID_5, 0, 5, 0, 52, 1, 100, 0, 1, @ENTRY, 0, 0, 50, 186471, 15000, 0, 0, 0, 0, 8, 0, 0, 0, -5149.791992, -590.198792, 397.323730, 4.39, "Gordok Brew Barker - On Text Over - Summon Super Brew Stein Trap (P1)"), 
(-@GUID_5, 0, 6, 0, 38, 0, 100, 0, 4, 4, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gordok Brew Barker - On Data Set - Set Phase 0"), -- Event is over, so set phase 0
-- Durotar version
(-@GUID_6, 0, 0, 0, 22, 0, 100, 0, 101, 5000, 5000, 0, 11, @SPELL_DRINK, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Gordok Brew Barker - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"), 
(-@GUID_6, 0, 1, 0, 1, 0, 100, 0, 30000, 45000, 180000, 240000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Gordok Brew Barker - Out of Combat - Yell Line 0 (random)"), 
(-@GUID_6, 0, 2, 0, 38, 0, 100, 0, 3, 3, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gordok Brew Barker - On Data Set - Set Phase 1"), 
(-@GUID_6, 0, 3, 0, 1, 1, 100, 0, 10000, 35000, 45000, 50000, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Gordok Brew Barker - Out of Combat - Say Line 2 (random) (P1)"), 
(-@GUID_6, 0, 4, 0, 1, 1, 100, 1, 3, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gordok Brew Barker - Out of Combat - Yell Line 1 (P1)"), 
(-@GUID_6, 0, 5, 0, 52, 1, 100, 0, 1, @ENTRY, 0, 0, 50, 186471, 15000, 0, 0, 0, 0, 8, 0, 0, 0, 1216.599976, -4284.270020, 21.290300, 3.787360, "Gordok Brew Barker - On Text Over - Summon Super Brew Stein Trap (P1)"), 
(-@GUID_6, 0, 6, 0, 38, 0, 100, 0, 4, 4, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gordok Brew Barker - On Data Set - Set Phase 0"); -- Event is over, so set phase 0
-- Text
DELETE FROM `script_texts` WHERE `entry` BETWEEN -717 AND -719; -- Old entries used in EAI
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ENTRY, 0, 0, "YOU TRY DA' BEST, NOW TRY DA' REST! OGRE BREW!", 14, 0, 100, 1, 0, 0, "Gordok Brew Barker"), 
(@ENTRY, 0, 1, "HEY YOU! DRINK OGRE BREWS! MAKE YOU BIG AND STRONG!", 14, 0, 100, 1, 0, 0, "Gordok Brew Barker"), 
(@ENTRY, 0, 2, "YOU WANT DRINK? WE GOT DRINK!", 14, 0, 100, 1, 0, 0, "Gordok Brew Barker"), 
(@ENTRY, 1, 0, "SOMEONE TRY THIS SUPER BREW!", 14, 0, 100, 0, 0, 0, "Gordok Brew Barker");
 
-- Глашатай из клана Черного Железа
-- We are making him invisible (model 16925) at all times because else we can not run the event properly (since we spawned it).
-- We are also setting phase so the yells and such will only happen during the event
SET @ENTRY := 24536;
SET @SPELL_PLANS_A := 48145;
SET @SPELL_PLANS_H := 49318;
UPDATE `creature_template` SET `AIName`='SmartAI', `modelid1`=16925, `flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@GUID_3, -@GUID_4, @ENTRY*100, @ENTRY*100+1, @ENTRY*100+2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
-- Durotar
(-@GUID_3, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Data Set - Yell Line 0"), 
(-@GUID_3, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 11, 24484, 100, 0, 0, 0, 0, 0, "Dark Iron Herald - On Data Set - Set Data Brewfest Reveler"), 
(-@GUID_3, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Data Set - Set Phase 1"), 
(-@GUID_3, 0, 3, 0, 1, 1, 100, 0, 25000, 45000, 60000, 90000, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - Out of Combat - Say Line 1 (random)"), 
(-@GUID_3, 0, 4, 5, 1, 1, 100, 1, 295000, 295000, 300000, 300000, 45, 5, 5, 0, 0, 0, 0, 10, @GUID_1, 23703, 0, 0, 0, 0, 0, "Dark Iron Herald - Out of Combat - Set Data Dark Iron Event Generator"), -- Almost 5 minutes passed, retreat
(-@GUID_3, 0, 5, 0, 61, 1, 100, 0, 0, 0, 0, 0, 80, @ENTRY*100, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - Out of Combat - Run Script"), 
(@ENTRY*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Yell Line 3"), 
(@ENTRY*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 5, 5, 0, 0, 0, 0, 11, 23702, 100, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Set Data Thunderbrew Festive Keg"), 
(@ENTRY*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 5, 5, 0, 0, 0, 0, 11, 23706, 100, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Set Data Gordok Festive Keg"), 
(@ENTRY*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 5, 5, 0, 0, 0, 0, 11, 23700, 100, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Set Data Barleybrew Festive Keg"), 
(@ENTRY*100, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 11, @SPELL_PLANS_H, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Cast Players Won - H - Summon Dark Iron Dwarf Plans"), 
(@ENTRY*100, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 41, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Despawn"), 
(-@GUID_3, 0, 6, 0, 38, 1, 100, 0, 20, 20, 0, 0, 80, @ENTRY*100+2, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Data Set - Run Script"), -- Runs same script the alliance version does
-- Dun Morogh
(-@GUID_4, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Data Set - Yell Line 0"), 
(-@GUID_4, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 11, 24484, 100, 0, 0, 0, 0, 0, "Dark Iron Herald - On Data Set - Set Data Brewfest Reveler"), 
(-@GUID_4, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Data Set - Set Phase 1"), 
(-@GUID_4, 0, 3, 0, 1, 1, 100, 0, 25000, 45000, 60000, 90000, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - Out of Combat - Say Line 1 (random)"), 
(-@GUID_4, 0, 4, 5, 1, 1, 100, 1, 295000, 295000, 300000, 300000, 45, 5, 5, 0, 0, 0, 0, 10, @GUID_2, 23703, 0, 0, 0, 0, 0, "Dark Iron Herald - Out of Combat - Set Data Dark Iron Event Generator"), -- Almost 5 minutes passed, retreat
(-@GUID_4, 0, 5, 0, 61, 1, 100, 0, 0, 0, 0, 0, 80, @ENTRY*100+1, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - Out of Combat - Run Script"), 
(@ENTRY*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Yell Line 2"), 
(@ENTRY*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 5, 5, 0, 0, 0, 0, 11, 23702, 100, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Set Data Thunderbrew Festive Keg"), 
(@ENTRY*100+1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 5, 5, 0, 0, 0, 0, 11, 23706, 100, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Set Data Gordok Festive Keg"), 
(@ENTRY*100+1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 5, 5, 0, 0, 0, 0, 11, 23700, 100, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Set Data Barleybrew Festive Keg"), 
(@ENTRY*100+1, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 11, @SPELL_PLANS_A, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Cast Players Won - A - Summon Dark Iron Dwarf Plans"), 
(@ENTRY*100+1, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Despawn"), 
(-@GUID_4, 0, 6, 0, 38, 1, 100, 0, 20, 20, 0, 0, 80, @ENTRY*100+2, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Data Set - Run Script"), -- Runs same script the horde version does
(@ENTRY*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Yell Line 3"), 
(@ENTRY*100+2, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 78, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Call Script Reset"), 
(@ENTRY*100+2, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script - Despawn"), 
(@ENTRY*100+2, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 23894, 100, 0, 0, 0, 0, 0, "Dark Iron Herald - On Script 2 - Set Data Brewfest Dark Iron Spawn Bunny"); -- Unsummon the spawn bunnies so they won't summon more dwarfs while we are retreating
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ENTRY, 0, 0, "No one expects the Dark Iron dwarves!", 14, 0, 100, 0, 0, 11832, "Dark Iron Herald"),
(@ENTRY, 1, 0, "We'll drink yer stout and lager, $BDrain all the pints and kegs!$BWe'll drink and brawl and brawl and drink, $B'til we can't feel our legs!", 12, 0, 100, 0, 0, 0, "Dark Iron Herald"), 
(@ENTRY, 1, 1, "So lift a mug to Coren, $BAnd Hurley Blackbreath too!$BThis drink is weak, without much kick, $BBut oi! At least it's brew!", 12, 0, 100, 0, 0, 0, "Dark Iron Herald"), 
(@ENTRY, 1, 2, "And when the brew's all missin'$BTa Shadowforge we'll hop, $BA bitter toast ta Ragnaros...$B... but bring him not a drop!", 12, 0, 100, 0, 0, 0, "Dark Iron Herald"), 
(@ENTRY, 1, 3, "Oh, we're from Blackrock Mountain, $BWe've come ta drink yer brew!$BDark Iron dwarves, they do not lie, $BAnd so yeh know it's true!", 12, 0, 100, 0, 0, 0, "Dark Iron Herald"), 
(@ENTRY, 1, 4, "Yeh will not try our bitter, $BYeh will not serve our ale!$BBut have Brewfest without our lot?$BJust try it, and ye'll fail!", 12, 0, 100, 0, 0, 0, "Dark Iron Herald"), 
(@ENTRY, 2, 0, "RETREAT! We've taken a beating and had 0 casualties! We can't keep taking these losses! FALL BACK!!", 14, 0, 100, 0, 0, 0, "Dark Iron Herald"), -- Alliance
(@ENTRY, 3, 0, "We did it boys! Now back to the Grim Guzzler and we'll drink to the 0 that were injured!!", 14, 0, 100, 0, 0, 0, "Dark Iron Herald"); -- Horde

-- [DND] Brewfest Dark Iron Spawn Bunny SAI
SET @ENTRY := 23894;
SET @SPELL_MOLE_MACHINE_SPAWN := 43563;
SET @SPELL_GROUND_SHAKE := 44210;
UPDATE `creature_template` SET `AIName`='SmartAI', `flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY, @ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 1, 5000, 275000, 280000, 280000, 11, @SPELL_MOLE_MACHINE_SPAWN, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Spawn Bunny - Out of Combat - Cast Mole Machine Spawn"), 
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, @ENTRY*100, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Spawn Bunny - On Mole Machine Spawn - Run Script"), 
(@ENTRY*100, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 12, 23709, 1, 300000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 3.85, "[DND] Brewfest Dark Iron Spawn Bunny - On Script - Spawn Dark Iron Guzzler"), 
(@ENTRY*100, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 12, 23709, 1, 300000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 5.58, "[DND] Brewfest Dark Iron Spawn Bunny - On Script - Spawn Dark Iron Guzzler"), 
(@ENTRY*100, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 12, 23709, 1, 300000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0.80, "[DND] Brewfest Dark Iron Spawn Bunny - On Script - Spawn Dark Iron Guzzler"), 
(@ENTRY*100, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 12, 23709, 1, 300000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2.48, "[DND] Brewfest Dark Iron Spawn Bunny - On Script - Spawn Dark Iron Guzzler"), 
(@ENTRY, 0, 2, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "[DND] Brewfest Dark Iron Spawn Bunny - On Data Set - Despawn");
 

 


 
-- Корен Худовар
-- DELETE FROM `instance_encounters` WHERE `entry` IN (895, 900);
-- INSERT INTO `instance_encounters` (`entry`, `creditType`, `creditEntry`, `lastEncounterDungeon`, `comment`) VALUES
-- (895, 0, 23872, 287, 'Coren Direbrew');
-- Send a mail on quest complete "Brew of the Month Club" - there is no wait time so we won't use RewMailDelaySecs
-- Alliance quest missed quest texts
SET @MAIL_A := 209;
UPDATE `quest_template` SET `RewMailTemplateId`= 0, `RewMailDelaySecs` = 0 WHERE `entry` = 12278;
UPDATE `quest_template` SET `RewMailTemplateId`=@MAIL_A, `RewMailDelaySecs` = 21600 WHERE `entry` = 12420;
UPDATE `quest_template` SET `OfferRewardText` = '', `RequestItemsText` = '' WHERE `entry` = 12278;
UPDATE `quest_template` SET `OfferRewardText` = 'Your paperwork looks to be in order. Welcome to the club, $N!$B$BYou can expect to get our mail at the start of every month. If you like what you got, stop by and we can sell you some more. This is the club that keeps on giving.', `RequestItemsText` = 'Do you have your membership forms filled out?' WHERE `entry` = 12420;
SET @MAIL_H := 210;
UPDATE `quest_template` SET `RewMailTemplateId`= 0, `RewMailDelaySecs` = 0 WHERE `entry` = 12306;
UPDATE `quest_template` SET `RewMailTemplateId`=@MAIL_H, `RewMailDelaySecs` = 21600 WHERE `entry` = 12421;
UPDATE `quest_template` SET `OfferRewardText` = '', `RequestItemsText` = '' WHERE `entry` = 12306;
UPDATE `quest_template` SET `OfferRewardText` = 'So you be joinin'' our ranks, $N? We treat ya nice here. You only get the best when you part of dis club!$B$BWe be sendin'' out brew to you at da start of every month. If you like what you got, and you be wantin'' more, head back over here. We make sure you get more of da brew you like.', `RequestItemsText` = 'Do ya have your membership forms filled out?' WHERE `entry` = 12421;

-- ХАК переместить спаун в скрипт
SET @GUID := 2710572; -- guid заменить для ytdb
DELETE FROM `gameobject` WHERE `guid` IN (@GUID, @GUID+1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@GUID, 189989, 0, 1, 1, -5154.36, -609.284, 398.452, 2.13369, 0, 0, 0.875682, 0.482887, 300, 0, 1), 
(@GUID+1, 189990, 1, 1, 1, 1198.66, -4297.37, 21.3811, 4.92821, 0, 0, 0.626838, -0.77915, 300, 0, 1);
DELETE FROM `game_event_gameobject` WHERE `guid` IN (@GUID, @GUID+1);
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(26, @GUID), 
(26, @GUID+1);