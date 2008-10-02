ALTER TABLE `realmd`.`account`
  ADD `v` longtext AFTER `sessionkey`,
  ADD `s` longtext AFTER `v`;