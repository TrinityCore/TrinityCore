-- ScriptName Update
UPDATE creature_template SET ScriptName='npc_taxi' WHERE entry=23816;
-- Auto-Complete problem fix by joschiwald
UPDATE `conditions` SET `ConditionTypeOrReference`=28 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8894 AND `SourceEntry`=0 AND `ConditionValue1`=11229;

