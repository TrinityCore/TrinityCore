--
UPDATE `creature` SET `PhaseId`=169 WHERE `phaseMask`=1;
UPDATE `creature` SET `PhaseId`=170 WHERE `phaseMask`=2;
UPDATE `creature` SET `PhaseId`=171 WHERE `phaseMask`=4;
UPDATE `creature` SET `PhaseId`=172 WHERE `phaseMask`=8;
UPDATE `creature` SET `PhaseId`=173 WHERE `phaseMask`=16;
UPDATE `creature` SET `PhaseId`=174 WHERE `phaseMask`=32;
UPDATE `creature` SET `PhaseId`=175 WHERE `phaseMask`=64;
UPDATE `creature` SET `PhaseId`=176 WHERE `phaseMask`=128;
UPDATE `creature` SET `PhaseId`=177 WHERE `phaseMask`=256;
UPDATE `creature` SET `PhaseId`=178 WHERE `phaseMask`=512;
UPDATE `creature` SET `PhaseGroup`=371 WHERE `phaseMask`=3; -- phasemask 1, 2 (phaseid 169, 170)
UPDATE `creature` SET `PhaseGroup`=396 WHERE `phaseMask`=5; -- phasemask 1, 4 (phaseid 169, 171)
UPDATE `creature` SET `PhaseGroup`=368 WHERE `phaseMask`=7; -- phasemask 1, 2, 4 (phaseid 169, 170, 171)
UPDATE `creature` SET `PhaseGroup`=392 WHERE `phaseMask`=10; -- phasemask 2, 8 (phaseid 170, 172)

UPDATE `creature` SET `PhaseGroup`=367 WHERE `phaseMask`=12; -- phasemask 4, 8 (phaseid 171, 172)
UPDATE `creature` SET `PhaseGroup`=391 WHERE `phaseMask`=17; -- phasemask 1, 16 (phaseid 169, 173)

UPDATE `creature` SET `PhaseGroup`=374 WHERE `phaseMask`=49; -- phasemask 1, 16, 32 (phaseid 169, 173, 174)
UPDATE `creature` SET `PhaseGroup`=394 WHERE `phaseMask`=66; -- phasemask 2, 64 (phaseid 170, 175)
UPDATE `creature` SET `PhaseGroup`=408 WHERE `phaseMask`=69; -- phasemask 1, 4, 64 (phaseid 169, 170, 175)
UPDATE `creature` SET `PhaseGroup`=375 WHERE `phaseMask`=129; -- phasemask 1, 128 (phaseid 169, 176)

UPDATE `creature` SET `PhaseGroup`=369 WHERE `phaseMask`=192; -- phasemask 64, 128 (phaseid 175, 176)
UPDATE `creature` SET `PhaseGroup`=397 WHERE `phaseMask`=193; -- phasemask 1, 64, 128 (phaseid 169, 175, 176)

UPDATE `creature` SET `PhaseGroup`=387 WHERE `phaseMask`=202; -- phasemask 2, 4, 64, 128 (phaseid 170, 171, 175, 176)

UPDATE `creature` SET `PhaseGroup`=370 WHERE `phaseMask`=257; -- phasemask 1, 256 (phaseid 169, 177)
UPDATE `creature` SET `PhaseGroup`=373 WHERE `phaseMask`=271; -- phasemask 1, 2, 4, 8, 256 (phaseid 169, 170, 171, 172, 177)

UPDATE `creature` SET `PhaseGroup`=376 WHERE `phaseMask`=511; -- phasemask 1, 2, 4, 8, 16, 32, 64, 128, 256 (phaseid 169, 170, 171, 172, 173, 174, 175, 176, 177)
UPDATE `creature` SET `PhaseGroup`=372 WHERE `phaseMask`=1023; -- phasemask 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 (phaseid 169, 170, 171, 172, 173, 174, 175, 176, 177, 178)
