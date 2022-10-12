INSERT INTO `spell_visual_send` (`spell_id`, `visual`, `unk1`, `unk2`, `speed`, `position`, `type`, `comment`) VALUES('145712','34115','0','0','25','0','0',NULL);
INSERT INTO `spell_visual_send` (`spell_id`, `visual`, `unk1`, `unk2`, `speed`, `position`, `type`, `comment`) VALUES('145714','34539','0','0','1','1','0',NULL);
insert into `spell_script_names` (`spell_id`, `ScriptName`) values('145712','spell_boss_gusting_bomb');

ALTER TABLE `spell_visual_send`
  ADD COLUMN `type` INT(3) DEFAULT 0  NOT NULL AFTER `position`;
insert into `spell_visual_send` (`spell_id`, `visual`, `unk1`, `unk2`, `speed`, `position`, `type`, `comment`) values('145288','32969','0','0','5','1','1','Искажение материи - при наложении ауры');
insert into `spell_visual_send` (`spell_id`, `visual`, `unk1`, `unk2`, `speed`, `position`, `type`, `comment`) values('145288','33807','0','0','1.5','1','1','Искажение материи - при касте');
insert into `spell_script_names` (`spell_id`, `ScriptName`) values('145288','spell_boss_matter_scramble');
insert into `spell_script_names` (`spell_id`, `ScriptName`) values('145369','spell_boss_matter_scramble_filter');
insert into `spell_script_names` (`spell_id`, `ScriptName`) values('142983','spell_boss_torment');
insert into `spell_script_names` (`spell_id`, `ScriptName`) values('142942','spell_boss_torment_visual');
insert into `spell_script_names` (`spell_id`, `ScriptName`) values('146098','spell_spoils_staff_of_resonating_water');

delete from areatrigger_data where entry = 1239;
insert into `areatrigger_data` (`entry`, `spellId`, `customEntry`, `customVisualId`, `Radius`, `RadiusTarget`, `Height`, `HeightTarget`, `Float4`, `Float5`, `isMoving`, `moveType`, `speed`, `activationDelay`, `updateDelay`, `maxCount`, `hitType`, `MoveCurveID`, `ElapsedTime`, `MorphCurveID`, `FacingCurveID`, `ScaleCurveID`, `HasFollowsTerrain`, `HasAttached`, `HasAbsoluteOrientation`, `HasDynamicShape`, `HasFaceMovementDir`, `windX`, `windY`, `windZ`, `windSpeed`, `windType`, `polygon`, `comment`) values('1239','146098','5203','33381','1','6','0','0','0','0','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','Посох резонирующей воды');
