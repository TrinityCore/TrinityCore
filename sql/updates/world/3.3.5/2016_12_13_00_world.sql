UPDATE `creature_template` SET `AIName`='' WHERE `entry`=23472;

-- Condition for spell Fixate
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=41295;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,41295,0,0,31,0,3,23418,0,0,0,0,'','Effect_0 hits Essence of Suffering');

DELETE FROM `creature_template_addon` WHERE `entry`=23418;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(23418, 0, 0, 0, 1, 0,'41296 41623');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN('spell_reliquary_of_souls_aura_of_desire','spell_reliquary_of_souls_submerge','spell_reliquary_of_souls_spite','spell_soul_fragment_anger','spell_reliquary_of_souls_frenzy');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(41350,'spell_reliquary_of_souls_aura_of_desire'),
(28819,'spell_reliquary_of_souls_submerge'),
(41376,'spell_reliquary_of_souls_spite'),
(41986,'spell_soul_fragment_anger'),
(41305,'spell_reliquary_of_souls_frenzy');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-41376 AND`spell_effect`=41377 AND`type`=0;

UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=1126, `flags_extra`=0, `ScriptName`='npc_angered_soul_fragment' WHERE `entry`=23398;

DELETE FROM `spell_proc` WHERE `SpellId`=41350;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(41350, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0, 0x1, 0x2, 0x0, 0x2, 0, 0, 0, 0);

DELETE FROM `creature_text` WHERE `entry`=23418;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(23418,0,0,'Pain and suffering are all that await you!',14,0,100,0,0,11415,21759,0,'SUFF_SAY_AGRO'),
(23418,1,0,'Don\'t leave me alone!',14,0,100,0,0,11416,21760,0,'SUFF_SAY_SLAY'),
(23418,1,1,'Look at what you made me do!',14,0,100,0,0,11417,21761,0,'SUFF_SAY_SLAY2'),
(23418,1,2,'I didn\'t ask for this!',14,0,100,0,0,11418,21762,0,'SUFF_SAY_SLAY3'),
(23418,2,0,'The pain is only beginning...',14,0,100,0,0,11419,21763,0,'SUFF_SAY_ENRAGE'),
(23418,3,0,'I don\'t want to go back!',14,0,100,0,0,11420,21764,0,'SUFF_SAY_RECAP'),
(23418,4,0,'Now what do I do?',14,0,100,0,0,11421,21765,0,'SUFF_SAY_AFTER'),
(23418,5,0,'%s becomes enraged!',41,0,100,0,0,0,24144,0,'SUFF_EMOTE_ENRAGE');

DELETE FROM `creature_text` WHERE `entry`=23419;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(23419,0,0,'You can have anything you desire... for a price.',14,0,100,0,0,11408,21752,0,'DESI_SAY_FREED'),
(23419,1,0,'Fulfillment is at hand.',14,0,100,0,0,11409,21753,0,'DESI_SAY_SLAY1'),
(23419,1,1,'Yes, you\'ll stay with us now...',14,0,100,0,0,11410,21754,0,'DESI_SAY_SLAY2'),
(23419,1,2,'Your reach exceeds your grasp.',14,0,100,0,0,11412,21756,0,'DESI_SAY_SLAY3'),
(23419,2,0,'Be careful what you wish for.',14,0,100,0,0,11411,21755,0,'DESI_SAY_SPEC'),
(23419,3,0,'I won\'t be far!',14,0,100,0,0,11414,21758,0,'DESI_SAY_RECAP'),
(23419,4,0,'I\'ll be waiting.',14,0,100,0,0,11413,21757,0,'DESI_SAY_AFTER');

DELETE FROM `creature_text` WHERE `entry`=23420;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(23420,0,0,'Beware: I live!',14,0,100,0,0,11399,21746,0,'ANGER_SAY_FREED'),
(23420,1,0,'So... foolish.',14,0,100,0,0,11400,21747,0,'ANGER_SAY_FREED2'),
(23420,2,0,'Enough! No more!',14,0,100,0,0,11402,21748,0,'ANGER_SAY_SEETHE'),
(23420,3,0,'%s seethes in anger!',14,0,100,0,0,0,21878,0,'ANGER_EMOTE_SEETHE'),
(23420,4,0,'On your knees!',14,0,100,0,0,11403,21749,0,'ANGER_SAY_SPEC'),
(23420,5,0,'Beware, coward!',14,0,100,0,0,11405,21751,0,'ANGER_SAY_SPITE'),
(23420,6,0,'I won\'t... be... ignored!',14,0,100,0,0,11404,21750,0,'ANGER_SAY_DEATH');
