ALTER TABLE `quest_template` 
  CHANGE `srcItem` `SrcItemId` int(11) unsigned NOT NULL default '0',
  ADD `SrcSpell` int(11) unsigned NOT NULL default '0' AFTER `SrcItemCount`;
