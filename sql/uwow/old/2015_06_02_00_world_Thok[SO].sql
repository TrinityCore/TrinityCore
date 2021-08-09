INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '143773','spell_freezing_breath'); 
DELETE FROM `spell_target_filter` WHERE `spellId` = '143800';
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) values('143800','15','22','-143777','-143773','0','0','0','7','2','4','8','0','0','OO: Icy Blood');
