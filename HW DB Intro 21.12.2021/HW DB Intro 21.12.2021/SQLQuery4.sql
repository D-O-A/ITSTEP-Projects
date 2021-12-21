ALTER TABLE Literals ADD money_value MONEY DEFAULT 0;

INSERT INTO Literals (num_value, txt_value) VALUES(42, 'HW Row');

SELECT * FROM Literals;