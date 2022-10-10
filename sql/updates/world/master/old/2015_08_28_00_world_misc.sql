ALTER TABLE `areatrigger_data`   
  ADD COLUMN `waitTime` INT(10) DEFAULT 0  NOT NULL AFTER `moveType`;

update areatrigger_data set waitTime = 1000 where entry IN (1265);

ALTER TABLE `areatrigger_actions`
  ADD COLUMN `amount` INT(11) DEFAULT 0  NOT NULL AFTER `hitMaxCount`;

delete from areatrigger_actions where entry = 1239;
insert into `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('1239','0','1','9','136','146582','1','0','0','0','0','0','100000','OO: Staff of Resonating Water - Heal');
insert into `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('1239','1','1','0','2','146679','0','0','0','0','0','0','0','OO: Staff of Resonating Water - Dmg');
