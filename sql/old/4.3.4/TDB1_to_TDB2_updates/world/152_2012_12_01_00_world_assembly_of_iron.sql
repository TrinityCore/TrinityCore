DELETE FROM `script_texts` WHERE `entry` BETWEEN -1603047 AND -1603020;
DELETE FROM `creature_text` WHERE `entry` IN (32867,32927,32857);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(32867,0,0,'You will not defeat the Assembly of Iron so easily, invaders!',14,0,100,0,0,15674,'Steelbreaker - Aggro'),
(32867,1,0,'So fragile and weak!',14,0,100,0,0,15675,'Steelbreaker - Slay 1'),
(32867,1,1,'Flesh... such a hindrance.',14,0,100,0,0,15676,'Steelbreaker - Slay 2'),
(32867,2,0,'You seek the secrets of Ulduar? Then take them!',14,0,100,0,0,15677,'Steelbreaker - Power'),
(32867,3,0,'My death only serves to hasten your demise.',14,0,100,0,0,15678,'Steelbreaker - Death'),
(32867,4,0,'Impossible...',14,0,100,0,0,15679,'Steelbreaker - Encounter defeated'),
(32867,5,0,'This meeting of the Assembly of Iron is adjourned!',14,0,100,0,0,15680,'Steelbreaker - Berserk'),

(32927,0,0,'Nothing short of total decimation will suffice.',14,0,100,0,0,15657,'Runemaster Molgeim - Aggro'),
(32927,1,0,'The world suffers yet another insignificant loss.',14,0,100,0,0,15658,'Runemaster Molgeim - Slay 1'),
(32927,1,1,'Death is the price of your arrogance.',14,0,100,0,0,15659,'Runemaster Molgeim - Slay 2'),
(32927,2,0,'Decipher this!',14,0,100,0,0,15660,'Runemaster Molgeim - Rune of Death'),
(32927,3,0,'Face the lightning surge!',14,0,100,0,0,15661,'Runemaster Molgeim - Rune of Summon'),
(32927,4,0,'The legacy of storms shall not be undone.',14,0,100,0,0,15662,'Runemaster Molgeim - Death'),
(32927,5,0,'What have you gained from my defeat? You are no less doomed, mortals!',14,0,100,0,0,15663,'Runemaster Molgeim - Encounter defeated'),
(32927,6,0,'This meeting of the Assembly of Iron is adjourned!',14,0,100,0,0,15664,'Runemaster Molgeim - Berserk'),

(32857,0,0,'Whether the world''s greatest gnats or the world''s greatest heroes, you''re still only mortal!',14,0,100,0,0,15684,'Brundir - Aggro'),
(32857,1,0,'A merciful kill!',14,0,100,0,0,15685,'Brundir Slay 1'),
(32857,1,1,'HAH!',14,0,100,0,0,15686,'Brundir - Slay 2'),
(32857,2,0,'Stand still and stare into the light!',14,0,100,0,0,15687,'Brundir - Special'),
(32857,3,0,'Let the storm clouds rise and rain down death from above!',14,0,100,0,0,15688,'Brundir - Flight'),
(32857,4,0,'The power of the storm lives on...',14,0,100,0,0,15689,'Brundir - Death'),
(32857,5,0,'You rush headlong into the maw of madness!',14,0,100,0,0,15690,'Brundir - Encounter defeated'),
(32857,6,0,'This meeting of the Assembly of Iron is adjourned!',14,0,100,0,0,15691,'Brundir - Berserk'),
(32857,7,0,'%s begins to Overload!',41,0,100,0,0,0,'Brundir - Overload');

UPDATE `creature_template` SET `flags_extra`=128, `ScriptName`='' WHERE `entry`=33705; -- Rune of Power
UPDATE `creature_template` SET `flags_extra`=128, `ScriptName`='' WHERE `entry`=33051; -- Rune of Summoning
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=32958; -- Lightning Elemental

DELETE FROM `creature_template_addon` WHERE `entry` IN (33051,32958,33689,33705);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33051,0,0,0,0,0,'62019'), -- Rune of Summoning
(32958,0,0,0,0,0,'62052'), -- Lightning Elemental
(33689,0,0,0,0,0,'62052'), -- Lightning Elemental
(33705,0,0,0,0,0,'61974'); -- Rune of Power

DELETE FROM `spell_script_names` WHERE `spell_id`=62019; -- Rune of Summoning
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(62019 ,'spell_assembly_rune_of_summoning');
