UPDATE `creature_template_addon` SET `auras`='9036 9617' WHERE `entry`=13117; -- 13117 (Horde Spirit Guide) - Ghost, Ghost Visual
UPDATE `creature_template_addon` SET `auras`='9036 9617' WHERE `entry`=13116; -- 13116 (Alliance Spirit Guide) - Ghost, Ghost Visual
UPDATE `creature_template` SET `ScriptName`='npc_bg_spirit_guide' where `entry` IN (13116, 13117);
