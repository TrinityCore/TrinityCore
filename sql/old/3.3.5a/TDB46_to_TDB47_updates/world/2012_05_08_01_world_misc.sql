-- Spell area spells for entering POS
DELETE FROM `spell_area` WHERE `spell` IN (70056,70057);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`) VALUES
(70056,4904,0,0,0,0,690,2,1), -- Send Script Event (22717)
(70057,4904,0,0,0,0,1101,2,1); -- Send Script Event (22718)

-- Fix flags and equipment for Ymirjar Deathbringer
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~256 WHERE `entry` IN (36892,37641);
UPDATE `creature_template` SET `equipment_id`=2444 WHERE `entry`=37641;
