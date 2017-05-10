--
DELETE FROM `smart_scripts` WHERE `entryorguid`=16522 AND `id`=12;
UPDATE `smart_scripts` SET `action_param1`=1 WHERE `entryorguid`=16522 AND `id`=0;
UPDATE `smart_scripts` SET `event_phase_mask`=1 WHERE entryorguid=16522 AND `id`=5;
UPDATE `smart_scripts` SET `event_phase_mask`=0, `event_flags`=0 WHERE `entryorguid`=16522 AND `id`=6;
UPDATE `smart_scripts` SET `event_phase_mask`=0 WHERE `entryorguid`=16522 AND `id`=7;
UPDATE `smart_scripts` SET `event_phase_mask`=2 WHERE `entryorguid`=16522 AND `id`=11;
UPDATE `smart_scripts` SET `event_phase_mask`=1, `action_param1`=1 WHERE entryorguid=16522 AND `id`=9;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `entryorguid`=16522 AND `id`=2;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `Entry`=17947;
