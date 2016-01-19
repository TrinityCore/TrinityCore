-- UPDATE`spell_dbc` SET `Effect1`=28, `EffectMiscValueB1`=64 WHERE  `Id`IN(14313,14307,14252);
UPDATE `spelleffect_dbc` SET `Effect`=28,`EffectMiscValueB`=64 WHERE `EffectSpellId` IN (14313,14307,14252);

-- Spell 14313 Summon Enraged Gryphon
-- Spell 14307 Summon Enraged Wyvern
-- Spell 14252 Summon Enraged Felbat
-- Spell 14329 Summon Enraged Hippogryph

DELETE FROM `smart_scripts` WHERE `source_type` =0 AND `action_type` =12 AND  `action_param1` =9297 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type` =0 AND `action_type` =12 AND  `action_param1` =9526 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type` =0 AND `action_type` =12 AND  `action_param1` =9521 AND `id`=1; 
DELETE FROM `smart_scripts` WHERE `source_type` =0 AND `action_type` =12 AND  `action_param1` =9527 AND `id`=1;

UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=14307, `action_param2`=2, `action_param3`=0,`link`=0 WHERE `source_type` =0 AND `action_type` =12 AND  `action_param1` =9297;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=14313, `action_param2`=2, `action_param3`=0,`link`=0 WHERE `source_type` =0 AND `action_type` =12 AND  `action_param1` =9526;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=14252, `action_param2`=2, `action_param3`=0,`link`=0 WHERE `source_type` =0 AND `action_type` =12 AND  `action_param1` =9521;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=14329, `action_param2`=2, `action_param3`=0,`link`=0 WHERE `source_type` =0 AND `action_type` =12 AND  `action_param1` =9527;
