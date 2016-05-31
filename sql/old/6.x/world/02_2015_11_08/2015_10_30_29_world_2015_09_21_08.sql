-- Update formation points
UPDATE `creature_formations` SET `point_1`=1, `point_2`=19 WHERE `leaderGUID`=127045 AND `memberGUID`=127058;
UPDATE `creature_formations` SET `point_1`=4, `point_2`=8 WHERE `leaderGUID`=201706 AND `memberGUID`=201764;
UPDATE `creature_formations` SET `angle`=270,`point_1`=4, `point_2`=7 WHERE `leaderGUID`=201713 AND `memberGUID`=201735;
UPDATE `creature_formations` SET `angle`=260, `point_1`=4, `point_2`=8 WHERE `leaderGUID`=202628 AND `memberGUID` IN (202680);
UPDATE `creature_formations` SET `angle`=100, `point_1`=4, `point_2`=8 WHERE `leaderGUID`=202628 AND `memberGUID` IN (202682);
UPDATE `creature_formations` SET `point_1`=2, `point_2`=7 WHERE `leaderGUID`=202629 AND `memberGUID` IN (202681,202684);
UPDATE `creature_formations` SET `point_1`=1, `point_2`=10 WHERE `leaderGUID`=202692 AND `memberGUID` IN (202695,202696);
UPDATE `creature_formations` SET `point_1`=2, `point_2`=7 WHERE `leaderGUID`=202814 AND `memberGUID` IN (202803,202804);
UPDATE `creature_formations` SET `point_1`=3, `point_2`=6 WHERE `leaderGUID`=202815 AND `memberGUID` IN (202805,202806);
