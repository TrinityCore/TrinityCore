-- ALTER TABLE realmd_db_version CHANGE COLUMN required_7938_01_realmd_account required_8332_01_realmd_realmcharacters bit;

ALTER TABLE realmcharacters
  ADD KEY (acctid);
