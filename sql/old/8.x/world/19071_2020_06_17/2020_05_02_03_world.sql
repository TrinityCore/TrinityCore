UPDATE creature_template SET `minlevel`=0 WHERE `minlevel`=1 AND `HealthScalingExpansion`=-1 AND `BaseAttackTime`=0; -- no attack time means we have no data and minlevel value was also defaulted
UPDATE creature_template SET `maxlevel`=0 WHERE `maxlevel`=1 AND `HealthScalingExpansion`=-1 AND `BaseAttackTime`=0; -- no attack time means we have no data and maxlevel value was also defaulted
UPDATE creature_template SET `minlevel`=`minlevel`-90 WHERE `minlevel`>=90 AND `minlevel`<100 AND `HealthScalingExpansion`=-1;
UPDATE creature_template SET `maxlevel`=`maxlevel`-90 WHERE `maxlevel`>=90 AND `maxlevel`<100 AND `HealthScalingExpansion`=-1;
UPDATE creature_template SET `minlevel`=`minlevel`-100 WHERE `minlevel`>=100 AND `minlevel`<110 AND `HealthScalingExpansion`=-1;
UPDATE creature_template SET `maxlevel`=`maxlevel`-100 WHERE `maxlevel`>=100 AND `maxlevel`<110 AND `HealthScalingExpansion`=-1;
UPDATE creature_template SET `minlevel`=`minlevel`-110 WHERE `minlevel`>=110 AND `minlevel`<120 AND `HealthScalingExpansion`=-1;
UPDATE creature_template SET `maxlevel`=`maxlevel`-110 WHERE `maxlevel`>=110 AND `maxlevel`<120 AND `HealthScalingExpansion`=-1;
UPDATE creature_template SET `minlevel`=`minlevel`-120 WHERE `minlevel`>=120 AND `minlevel`<130 AND `HealthScalingExpansion`=-1;
UPDATE creature_template SET `maxlevel`=`maxlevel`-120 WHERE `maxlevel`>=120 AND `maxlevel`<130 AND `HealthScalingExpansion`=-1;
