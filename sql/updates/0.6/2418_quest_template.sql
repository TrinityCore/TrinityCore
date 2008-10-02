ALTER TABLE `quest_template` 
  ADD `ReqSourceId1`  int(11) unsigned NOT NULL default '0' AFTER `ReqItemCount4` , 
  ADD `ReqSourceId2`  int(11) unsigned NOT NULL default '0' AFTER `ReqSourceId1`  , 
  ADD `ReqSourceId3`  int(11) unsigned NOT NULL default '0' AFTER `ReqSourceId2`  , 
  ADD `ReqSourceId4`  int(11) unsigned NOT NULL default '0' AFTER `ReqSourceId3`  , 
  ADD `ReqSourceRef1` int(11) unsigned NOT NULL default '0' AFTER `ReqSourceId4`  ,
  ADD `ReqSourceRef2` int(11) unsigned NOT NULL default '0' AFTER `ReqSourceRef1` ,
  ADD `ReqSourceRef3` int(11) unsigned NOT NULL default '0' AFTER `ReqSourceRef2` ,
  ADD `ReqSourceRef4` int(11) unsigned NOT NULL default '0' AFTER `ReqSourceRef3` ; 
