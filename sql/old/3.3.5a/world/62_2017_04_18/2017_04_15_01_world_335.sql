-- Remove unknown spell aura on creature Sergeant Major Skyshadow
UPDATE `creature_addon` SET `auras`='' WHERE `guid`=106950;
