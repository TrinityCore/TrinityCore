UPDATE `creature` SET `position_z`=-6.03356	WHERE `guid`=46069 AND `id`=11741; -- Dredge Crusher
UPDATE `creature` SET `position_z`=8.638660 WHERE `guid`=49069 AND `id`=11374; -- Hooktooth Frenzies
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` = 37231; -- Robe Beam Stalker
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` = 38008; -- Blood Orb Controller
UPDATE `playercreateinfo_action` SET `action`=26297 WHERE `action` IN (20554,50621,26635,26296) AND `race`=8; -- Berserking - Troll racial
