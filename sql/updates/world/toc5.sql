UPDATE `creature_template` SET `faction`=14, `unit_flags`= 2, `scriptName`='generic_vehicleAI_toc5' WHERE `entry` IN (33217,33316,33317,33318,33319,33320,33321,33322,33323,33324,34658,35633,35634,35635,35636,35637,35638,35640,35641,35768);
UPDATE `creature_template` SET `unit_flags`=33554690 WHERE `scriptname` like'boss%toc5';

UPDATE `creature_template` SET `gossip_menu_id`=10614 WHERE `entry`IN(35004,35005);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=10614;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(10614, 0, 0, 'I am ready.', 35320, 1, 1, 0, 0, 0, 0, '', 0),
(10614, 1, 0, 'I am ready for the next challenge.', 35538, 1, 1, 0, 0, 0, 0, '', 0),
(10614, 2, 0, 'I am ready.  However, I\'d like to skip the pageantry.', 36657, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10614; 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(15,10614,0,0,0,13,1,0,3,2,1,0,0,'','Show gossip option only if GrandChampions is not done'),
(15,10614,1,0,0,13,1,3,3,2,1,0,0,'','Show gossip option only if BlacKnight is not done'),
(15,10614,1,0,0,13,1,0,3,2,0,0,0,'','Show gossip option only if GrandChampions is done'),
(15,10614,2,0,0,13,1,0,3,2,1,0,0,'','Show gossip option only if GrandChampions is not done');

-- jaeren
DELETE FROM `creature_text` WHERE `entry`=35004;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(35004, 0, 0, 'The Sunreavers are proud to present their representatives in this trial by combat.', 14, 0, 100, 396, 0, 8574, 35260, 0, 'Jaeren Sunsworn - SAY_JAEREN_GRAND_CHAMPIONS_INTRO_1'),
(35004, 1, 0, 'Here comes the small but deadly Ambrose Boltspark, Grand Champion of Gnomeregan!', 12, 0, 100, 0, 0, 8573, 35248, 0, 'Jaeren Sunsworn - SAY_JAEREN_GRAND_CHAMPIONS_MAGE'),
(35004, 2, 0, 'Coming out of the gate is Colosos, the towering Grand Champion of the Exodar!', 12, 0, 100, 0, 0, 8573, 35247, 0, 'Jaeren Sunsworn - SAY_JAEREN_GRAND_CHAMPIONS_SHAMAN'),
(35004, 3, 0, 'Entering the arena is the Grand Champion of Darnassus, the skilled sentinel Jaelyne Evensong!', 12, 0, 100, 0, 0, 8573, 35249, 0, 'Jaeren Sunsworn - SAY_JAEREN_GRAND_CHAMPIONS_HUNTER'),
(35004, 4, 0, 'Proud and strong, give a cheer for Marshal Jacob Alerius, the Grand Champion of Stormwind!', 12, 0, 100, 0, 0, 8573, 35245, 0, 'Jaeren Sunsworn - SAY_JAEREN_GRAND_CHAMPIONS_WARRIOR'),
(35004, 5, 0, 'The might of the dwarves is represented today by the Grand Champion of Ironforge, Lana Stouthammer!', 12, 0, 100, 0, 0, 8573, 35246, 0, 'Jaeren Sunsworn - SAY_JAEREN_GRAND_CHAMPIONS_ROUGUE'),
(35004, 6, 0, 'Entering the arena, a paladin who is no stranger to the battlefield or tournament ground, the Grand Champion of the Argent Crusade, Eadric the Pure!', 12, 0, 100, 0, 0, 8574, 35542, 0, 'Jaeren Sunsworn - SAY_JAEREN_EADRIC_INTRO'),
(35004, 7, 0, 'The next combatant is second to none in her passion for upholding the Light. I give you Argent Confessor Paletress!', 14, 0, 100, 0, 0, 8574, 35543, 0, 'Jaeren Sunsworn - SAY_JAEREN_PALETRESS_INTRO'),
(35004, 8, 0, 'What\'s that, up near the rafters?', 12, 0, 100, 25, 0, 0, 35545, 0, 'Jaeren Sunsworn - SAY_JAEREN_KNIGHT_INTRO');

-- arelas
DELETE FROM `creature_text` WHERE `entry`=35005;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(35005, 0, 0, 'The Silver Covenant is pleased to present their contenders for this event, Highlord.', 14, 0, 100, 396, 0, 8574, 35259, 0, 'Arelas Brightstar - SAY_ARELAS_GRAND_CHAMPIONS_INTRO_1'),
(35005, 1, 0, 'Coming out of the gate is Eressea Dawnsinger, skilled mage and Grand Champion of Silvermoon!\n', 12, 0, 100, 0, 0, 8573, 35338, 0, 'Arelas Brightstar - SAY_ARELAS_GRAND_CHAMPIONS_MAGE'),
(35005, 2, 0, 'Tall in the saddle of his kodo, here is the venerable Runok Wildmane, Grand Champion of Thunder Bluff!\n', 12, 0, 100, 0, 0, 8573, 35336, 0, 'Arelas Brightstar - SAY_ARELAS_GRAND_CHAMPIONS_SHAMAN'),
(35005, 3, 0, 'Entering the arena is the lean and dangerous Zul\'tore, Grand Champion of Sen\'jin!\n', 12, 0, 100, 0, 0, 8573, 35335, 0, 'Arelas Brightstar - SAY_ARELAS_GRAND_CHAMPIONS_HUNTER'),
(35005, 4, 0, 'Presenting the fierce Grand Champion of Orgrimmar, Mokra the Skullcrusher!\n', 12, 0, 100, 0, 0, 8573, 35334, 0, 'Arelas Brightstar - SAY_ARELAS_GRAND_CHAMPIONS_WARRIOR'),
(35005, 5, 0, 'Representing the tenacity of the Forsaken, here is the Grand Champion of the Undercity, Deathstalker Visceri!\n', 12, 0, 100, 0, 0, 8573, 35337, 0, 'Arelas Brightstar - SAY_ARELAS_GRAND_CHAMPIONS_ROUGUE'),
(35005, 6, 0, 'Entering the arena, a paladin who is no stranger to the battlefield or tournament ground, the Grand Champion of the Argent Crusade, Eadric the Pure!', 14, 0, 100, 0, 0, 8574, 35542, 0, 'Arelas Brightstar - SAY_EADRIC_INTRO'),
(35005, 7, 0, 'The next combatant is second to none in her passion for upholding the Light. I give you Argent Confessor Paletress!', 14, 0, 100, 0, 0, 8574, 35543, 0, 'Arelas Brightstar - SAY_ARELAS_PALETRESS_INTRO'),
(35005, 8, 0, 'What\'s that, up near the rafters?', 12, 0, 100, 25, 0, 0, 35545, 0, 'Arelas Brightstar - SAY_ARELAS_KNIGHT_INTRO');

-- varian
DELETE FROM `creature_text` WHERE `entry`=34990 AND `groupid`>=50;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(34990, 50, 0, 'I have no taste for these games, Tirion. Still... I trust they will perform admirably.', 12, 0, 100, 1, 0, 0, 35322, 0, 'King Varian Wrynn - GRAND_CHAMPIONS_INTRO_A'),
(34990, 51, 0, 'I did not come here to watch animals tear at each other senselessly, Tirion.', 12, 0, 100, 1, 0, 0, 35328, 0, 'King Varian Wrynn - GRAND_CHAMPIONS_INTRO_H'),
(34990, 52, 0, 'Don\'t just stand there; kill him!', 14, 0, 100, 22, 0, 0, 35550, 0, 'King Varian Wrynn - BLACK_KNIGHT_INTRO'),
(34990, 53, 0, 'You fought well.', 14, 0, 100, 66, 0, 0, 35795, 0, 'King Varian Wrynn - BLACK_KNIGHT_OUTRO');

-- garrosh
DELETE FROM `creature_text` WHERE `entry`=34995 AND `groupid`>=50;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(34995, 50, 0, 'Admirably? Hah! I will enjoy watching your weak little champions fail, human.', 14, 0, 100, 22, 0, 0, 35324, 0, 'Garrosh Hellscream - GRAND_CHAMPIONS_INTRO_A'),
(34995, 51, 0, 'Finally, a fight worth watching.', 12, 0, 100, 396, 0, 0, 35327, 0, 'Garrosh Hellscream - GRAND_CHAMPIONS_INTRO_H'),
(34995, 52, 0, 'Tear him apart!', 14, 0, 100, 22, 0, 0, 35551, 0, 'Garrosh Hellscream - BLACK_KNIGHT_INTRO');

-- jaina
DELETE FROM `creature_text` WHERE `entry`=34992;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(34992, 0, 0, 'Of course they will.', 12, 0, 100, 0, 0, 0, 0, 0, 'Jaina - GRAND_CHAMPIONS_INTRO_A'),
(34992, 1, 0, 'They are worthy fighters, you will see.', 14, 0, 100, 1, 0, 0, 0, 0, 'Jaina - GRAND_CHAMPIONS_INTRO_H');

-- thrall
DELETE FROM `creature_text` WHERE `entry`=34994;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(34994, 0, 0, 'Garrosh, enough.', 12, 0, 100, 396, 0, 0, 35325, 0, 'Thrall - GRAND_CHAMPIONS_INTRO_A'),
(34994, 1, 0, 'Fight well, Horde! Lok\'tar Ogar!', 14, 0, 100, 22, 0, 0, 35326, 0, 'Thrall - GRAND_CHAMPIONS_INTRO_H'),
(34994, 2, 0, 'Well done, Horde!', 14, 0, 100, 66, 0, 0, 35794, 0, 'Thrall - BLACK_KNIGHT_OUTRO');
