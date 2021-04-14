-- Explicitly set the account-table to use INNODB-engine (to allow foreign keys and transactions)
ALTER TABLE account ENGINE=InnoDB;
