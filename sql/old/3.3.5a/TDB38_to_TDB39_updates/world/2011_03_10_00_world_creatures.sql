UPDATE `creature_template` SET `flags_extra`=((`flags_extra`|128)&~2) WHERE `entry` IN (38153,26043,37181,37702,37183,36848,37547,37519,37215,38463,38319,38879); -- Various triggers in ICC

-- Delete gunship spawns
DELETE FROM `creature` WHERE `id` IN (37547,37519,37215,36971,37227,36961,36969,36950,37116,36978,37540,37488);

DELETE FROM `creature_template_addon` WHERE `entry`=38463;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(38463,0,0,1,0, '72100 0'); -- Empowering Orb Visual Stalker

UPDATE `gameobject_template` SET `faction`=35, `flags`=16 WHERE `entry`=201741; -- Empowering Blood Orb
