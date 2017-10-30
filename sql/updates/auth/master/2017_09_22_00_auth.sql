ALTER TABLE `battlenet_accounts`
  ADD `LoginTicket` varchar(64),
  ADD `LoginTicketExpiry` int(10) unsigned;
