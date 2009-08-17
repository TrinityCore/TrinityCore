-- Distracting Jarven does not depend on taking quest from the guarded barrel, it's available while Bitter Rivals is active
update quest_template set PrevQuestID = -310 where entry = 308;

-- Make the unguarded barrel appear sooner after Jarven leaves
delete from `quest_end_scripts` where `id` = 308;
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','0','3','0','0','0','-5601.64','-541.38','392.42','0.5');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','0','0','0','0','2000000077','0','0','0','0');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','2','3','0','0','0','-5597.94','-542.04','392.42','5.5');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','3','3','0','0','0','-5597.95','-548.43','395.48','4.7');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','3','9','35875','30','0','0','0','0','0');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','7','3','0','0','0','-5605.31','-549.33','399.09','3.1');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','10','3','0','0','0','-5607.55','-546.63','399.09','1.5');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','14','3','0','0','0','-5597.52','-538.75','399.09','1.5');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','18','3','0','0','0','-5597.62','-530.24','399.65','3');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','21','3','0','0','0','-5603.67','-529.91','399.65','4.2');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','25','0','0','0','2000000056','0','0','0','0');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','36','3','0','0','0','-5603.67','-529.91','399.65','4.2');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','39','3','0','0','0','-5597.62','-530.24','399.65','3');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','42','3','0','0','0','-5597.52','-538.75','399.09','1.5');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','45','3','0','0','0','-5607.55','-546.63','399.09','1.5');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','48','3','0','0','0','-5605.31','-549.33','399.09','3.1');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','51','3','0','0','0','-5597.95','-548.43','395.48','4.7');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','54','3','0','0','0','-5597.94','-542.04','392.42','5.5');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','55','0','0','0','2000000078','0','0','0','0');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','58','3','0','0','0','-5601.64','-541.38','392.42','0.5');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','60','3','0','0','0','-5605.96','-544.45','392.43','0.9');
insert into `quest_end_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) values('308','62','0','0','0','2000000079','0','0','0','0');


