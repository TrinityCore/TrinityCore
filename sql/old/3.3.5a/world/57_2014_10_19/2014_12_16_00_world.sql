DELETE FROM `creature_text` WHERE `entry` IN(33662,33701,33626,33686,33696);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(33662, 0, 0, 'Any luck?', 12, 0, 100, 0, 0, 0, 34184, 'Kirin Tor Battle-Mage to Player'),
(33662, 1, 0, 'Keep at it. If our suspicions are right and this is a transporter, it could prove extremely useful in our assault.', 12, 0, 100, 0, 0, 0, 34186, 'Kirin Tor Battle-Mage to Player'),
(33701, 0, 0, 'I heard a story or two of a Lore Keeper in Uldaman that fit your description. Do you serve a similar purpose?', 12, 0, 100, 0, 0, 0, 33702, 'High Explorer Dellorah to Player'),
(33701, 1, 0, 'Frontal defense systems? Is there something I should let Brann know before he has anyone attempt to enter the complex?', 12, 0, 100, 0, 0, 0, 33704, 'High Explorer Dellorah to Player'),
(33701, 2, 0, 'Can you detail the nature of these defense systems?', 12, 0, 100, 0, 0, 0, 33706, 'High Explorer Dellorah to Player'),
(33701, 3, 0, 'Got it. At least we don''t have to deal with those orbital emplacements.', 12, 0, 100, 0, 0, 0, 33708, 'High Explorer Dellorah to Player'),
(33701, 4, 0, 'Rhydian, make sure you let Brann and Archmage Pentarus know about those defenses immediately.', 12, 0, 100, 0, 0, 0, 33709, 'High Explorer Dellorah to Player'),
(33701, 5, 0, 'And you mentioned an imprisoned entity? What is the nature of this entity and what is its status?', 12, 0, 100, 0, 0, 0, 33710, 'High Explorer Dellorah to Player'),
(33701, 6, 0, 'Yogg-Saron is here? It sounds like we really will have our hands full then.', 12, 0, 100, 0, 0, 0, 33713, 'High Explorer Dellorah to Player'),
(33626, 0, 0, 'Not a bit. For the life of me, I can''t figure out how this thing works.', 12, 0, 100, 0, 0, 0, 34183, 'Hired Engineer to Player'),
(33626, 1, 0, 'I know, I know... I haven''t given up yet. Don''t get your hopes up though, this technology is way beyond me.', 12, 0, 100, 0, 0, 0, 34187, 'Hired Engineer to Player'),
(33686, 0, 0, 'I was constructed to serve as a repository for essential information regarding this complex. My primary functions include communicating the status of the frontal defense systems and assessing the status of the entity that this complex was built to imprison.', 12, 0, 100, 0, 0, 0, 33703, 'Lore Keeper of Norgannon to Player'),
(33686, 1, 0, 'Compromise of complex detected, security override enabled - query permitted.', 12, 0, 100, 0, 0, 0, 33707, 'Lore Keeper of Norgannon to Player'),
(33686, 2, 0, 'Primary defensive emplacements consist of iron constructs and Storm Beacons, which will generate additional constructs as necessary. Secondary systems consist of orbital defense emplacements.', 12, 0, 100, 0, 0, 0, 33712, 'Lore Keeper of Norgannon to Player'),
(33686, 3, 0, 'Entity designate: Yogg-Saron. Security has been compromised. Prison operational status unknown. Unable to contact Watchers for notification purposes.', 12, 0, 100, 0, 0, 0, 33711, 'Lore Keeper of Norgannon to Player'),
(33696, 0, 0, '%s nods.', 16, 0, 100, 0, 0, 0, 33715, 'Archmage Rhydian to Player'),
(33696, 1, 0, '%s whispers something to Brann.', 16, 0, 100, 0, 0, 0, 33716, 'Archmage Rhydian to Player');

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(33662,33701,33696);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(33696,33701,-136527) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(3369600,3370100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-136527,0,0,0,10,0,100,0,1,40,90000,120000,80,3369600,2,0,0,0,0,1,0,0,0,0,0,0,0,'Kirin Tor Battle-Mage - OOC Los - Run Script'),
(33701,0,0,0,10,0,100,1,1,40,30000,60000,80,3370100,2,0,0,0,0,1,0,0,0,0,0,0,0,'High Explorer Dellorah - OOC Los - Run Script (No repeat)'),
(33696,0,0,0,38,0,100,0,1,1,0,0,1,0,2000,0,0,0,0,1,0,0,0,0,0,0,0,'Archmage Rhydian - On Data Set - Say Line 0'),
(33696,0,1,0,52,0,100,0,0,33696,0,0,53,1,33696,0,0,0,0,1,0,0,0,0,0,0,0,'Archmage Rhydian - On Text Over (Line 0) - Start WP'),
(33696,0,2,3,40,0,100,0,8,33696,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archmage Rhydian - On Reached WP8 - Pause WP'),
(33696,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Archmage Rhydian - On Reached WP8 - Say Line 1'),
(33696,0,4,0,40,0,100,0,10,33696,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.916666,'Archmage Rhydian - On Reached WP10 - Set Orientation'),
(3369600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kirin Tor Battle-Mage - Script - Say Line 0'),
(3369600, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 33626, 0, 0, 0, 0, 0, 0, 'Kirin Tor Battle-Mage - Script - Say Line 0 (Hired Engineer)'),
(3369600, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kirin Tor Battle-Mage - Script - Say Line 1'),
(3369600, 9, 3, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 33626, 0, 0, 0, 0, 0, 0, 'Kirin Tor Battle-Mage - Script - Say Line 1 (Hired Engineer)'),
(3370100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 0'),
(3370100, 9, 1, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 33686, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 0 (Lore Keeper of Norgannon)'),
(3370100, 9, 2, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 1'),
(3370100, 9, 3, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 2'),
(3370100, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 33686, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 1 (Lore Keeper of Norgannon)'),
(3370100, 9, 5, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 33686, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 2 (Lore Keeper of Norgannon)'),
(3370100, 9, 6, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 3'),
(3370100, 9, 7, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 4'),
(3370100, 9, 8, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 5'),
(3370100, 9, 9, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 33696, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Set Data to Archmage Rhydian'),
(3370100, 9, 10, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 33686 , 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 3 (Lore Keeper of Norgannon)'),
(3370100, 9, 11, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High Explorer Dellorah - Script - Say Line 6');

DELETE FROM `waypoints` WHERE `entry`=33696;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(33696, 1, -769.512 ,-120.8109 ,429.5509, 'Archmage Rhydian'),
(33696, 2, -769.1432 ,-104.0848 ,429.8661, 'Archmage Rhydian'),
(33696, 3, -763.0945 ,-86.176 ,429.9557, 'Archmage Rhydian'),
(33696, 4, -755.0403 ,-68.30566 ,429.9557, 'Archmage Rhydian'),
(33696, 5, -746.3733 ,-54.03885 ,429.9657, 'Archmage Rhydian'),
(33696, 6, -738.9852 ,-49.87864 ,429.9657, 'Archmage Rhydian'),
(33696, 7, -729.1484 ,-49.88547 ,429.9657, 'Archmage Rhydian'),
(33696, 8, -718.4777 ,-52.54433 ,429.8407, 'Archmage Rhydian'),
(33696, 9, -768.5124 ,-112.0747 ,429.8398, 'Archmage Rhydian'),
(33696, 10, -773.566 ,-144.6838 ,429.9191, 'Archmage Rhydian');
