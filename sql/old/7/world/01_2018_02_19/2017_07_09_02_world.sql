-- Fix impaled Blackrock Orc
UPDATE `creature_template` SET `dynamicflags`=64, `InhabitType`=4 WHERE `entry`=43150;
UPDATE `creature_template_addon` SET `aiAnimKit`=721 WHERE `entry`=43150;
