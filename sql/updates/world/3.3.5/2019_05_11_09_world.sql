-- 
UPDATE `creature` SET `id`=18663, `curhealth`=8104, `curmana`=7888 WHERE `guid`=66904 AND `id`=18641;
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid` IN (66868, 66806);
UPDATE `smart_scripts` SET `event_type`=16, `event_flags`=6, `event_param1`=33482, `event_param2`=15, `event_param3`=8000, `event_param4`=12000, `action_param2`=0, `target_type`=7,`target_param1`=0, `comment`="Cabal Acolyte - On Friendly missing aura - Cast 'Shadow Defense'"  WHERE `entryorguid` IN(18633) AND `source_type`=0 AND `id`=0;
