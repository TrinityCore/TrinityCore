-- Correct run speed, models, and trigger flag
UPDATE `creature_template` SET `speed_run`=5.5/7, `modelid1`=1126, `modelid2`=11686, `flags_extra`= `flags_extra`|128 WHERE `entry` IN(33632,33802);

-- NullAI for semi-triggers (flags_extra|128 would make them unattackable by certain spells needed for the encounter)
UPDATE `creature_template` SET `AIName`='NullAI' WHERE `entry` IN(33742,33809,33942);