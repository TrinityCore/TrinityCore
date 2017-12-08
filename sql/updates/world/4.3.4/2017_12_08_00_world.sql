-- Lost City of the Tol'vir trigger updates
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry` IN (37231, 48092, 50496);
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry` IN (37231, 48097);

-- Nordrassil fixups
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry` IN (49844, 41027, 41028, 42663, 42658, 42660, 42664, 42659, 42657);
