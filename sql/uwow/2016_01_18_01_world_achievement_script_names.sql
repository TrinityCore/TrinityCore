CREATE TABLE `achievement_script_names`(  
  `id` INT(11) NOT NULL,
  `ScriptName` VARCHAR(64) NOT NULL,
  UNIQUE INDEX `id` (`id`, `ScriptName`)
) ENGINE=MYISAM CHARSET=utf8 COLLATE=utf8_general_ci;

insert into `achievement_script_names` (`id`, `ScriptName`) values('8030','achievement_a_test_of_valor_kill');
insert into `achievement_script_names` (`id`, `ScriptName`) values('8031','achievement_a_test_of_valor_kill');
