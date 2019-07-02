DELETE FROM `creature_text` WHERE `CreatureID`=36627 AND `GroupID`=4;
DELETE FROM `creature_text` WHERE `CreatureID`=36899;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(36899,0,0,'%s grows more unstable!',16,0,0,0,0,0,36950,0,'Big Ooze - EMOTE_UNSTABLE_2'),
(36899,1,0,'%s is growing volatile!',16,0,0,0,0,0,36952,0,'Big Ooze - EMOTE_UNSTABLE_3'),
(36899,2,0,'%s can barely maintain its form!',16,0,0,0,0,0,36956,0,'Big Ooze - EMOTE_UNSTABLE_4'),
(36899,3,0,'|TInterface\\Icons\\spell_shadow_unstableaffliction_2.blp:16|t%s begins to cast |cFFFF0000Unstable Ooze Explosion!|r',41,0,0,0,0,0,37064,0,'Big Ooze - EMOTE_UNSTABLE_EXPLOSION');
