-- Active: 1700211904021@@127.0.0.1@3306@dml_ex_employeeswhotravel

-- The following are exercises on the data manipulation language (DML) aspect of SQL. Select, Insert, Update, Delete.
-- The table creations are just so that we have a sample database to run the queries against.
-- Database Schema (given in slides): https://iili.io/JRC5h6G.png
-- Database Schema (MySql Workbench > Database > Reverse Engineer): https://iili.io/JRC5moF.png

CREATE DATABASE DML_EX_EmployeesWhoTravel;

SHOW DATABASES; -- Showing all databases on the MySQL server

SELECT `SCHEMA_NAME` 
FROM `information_schema`.`SCHEMATA` 
WHERE `SCHEMA_NAME` NOT IN ('information_schema', 'mysql', 'performance_schema', 'sys'); -- This query retrieves only the user-created databases on the server not the default ones that come with it.

USE DML_EX_EmployeesWhoTravel;

-- Creating the tables

CREATE TABLE IF NOT EXISTS csz (
    zip INT PRIMARY KEY,
    city VARCHAR(255),
    state VARCHAR(255)
);

CREATE TABLE IF NOT EXISTS departments (
    dept_no INT PRIMARY KEY,
    dept_name VARCHAR(255)
);

CREATE TABLE IF NOT EXISTS emps (
    social_security_no INT PRIMARY KEY,
    name VARCHAR(255),
    address VARCHAR(255),
    zip INT,
    phone VARCHAR(20),
    dept_no INT,
    job_title VARCHAR(255),
    salary DECIMAL(10, 2),
    FOREIGN KEY (zip) REFERENCES csz(zip),
    FOREIGN KEY (dept_no) REFERENCES departments(dept_no)
);

CREATE TABLE IF NOT EXISTS trips (
    trip_id INT PRIMARY KEY,
    destination_city VARCHAR(255),
    departure_date DATE,
    return_date DATE,
    social_security_no INT,
    FOREIGN KEY (social_security_no) REFERENCES emps(social_security_no)
);

CREATE TABLE IF NOT EXISTS expenses (
    trip_id INT,
    item VARCHAR(255),
    date DATE,
    amount DECIMAL(10, 2),
    PRIMARY KEY (trip_id, item),
    FOREIGN KEY (trip_id) REFERENCES trips(trip_id)
);

SELECT COUNT(*) as table_count
FROM information_schema.tables
WHERE table_schema = DATABASE(); -- This query counts how many tables there are in the currently active database
-- It is a useful tool to verify whether we have successfully created all the desired tables

SHOW TABLES; -- To see all the table names / also another way of verification

-- Filling the tables

INSERT IGNORE INTO csz (zip, city, state)
VALUES
    (12345, 'Anytown', 'CA'),
    (54321, 'Othercity', 'NY'),
    (98765, 'London', NULL),
    (75001, 'Paris', NULL),
    (1000001, 'Tokyo', NULL),
    (100001, 'Beijing', NULL);

SELECT * FROM csz;

INSERT IGNORE INTO departments (dept_no, dept_name)
VALUES
    (1, 'IT'),
    (2, 'Sales'),
    (3, 'HR');

SELECT * FROM departments;

INSERT IGNORE INTO emps (social_security_no, name, address, zip, phone, dept_no, job_title, salary)
VALUES
    (111, 'John Doe', '123 Main St', 12345, '123456789', 1, 'Programmer', 80000.00),
    (222, 'Jane Smith', '456 Oak St', 54321, '987654321', 2, 'Sales Manager', 100000.00),
    (333, 'Bob Johnson', '789 High St', 98765, '555555555', 3, 'HR Representative', 70000.00),
    (444, 'Alice Cooper', '101 Rue Street', 75001, '111111111', 1, 'Programmer', 85000.00),
    (555, 'Eva Ford', '1 Tokyo Street', 1000001, '222222222', 2, 'Sales Manager', 120000.00),
    (666, 'David Gibson', '2 Beijing Street', 100001, '333333333', 3, 'HR Representative', 90000.00),
    (777, 'John Dough', '3 Bakery Street', 12345, '444444444', 1, 'Baker', 60000.00);

SELECT * FROM emps;

INSERT IGNORE INTO trips (trip_id, destination_city, departure_date, return_date, social_security_no)
VALUES
    (1, 'Paris', '2022-01-01', '2028-12-31', 111),
    (2, 'London', '2022-02-01', '2028-12-31', 222),
    (3, 'Tokyo', '2022-03-01', '2028-12-31', 333),
    (4, 'Beijing', '2022-04-01', '2022-04-10', 444),
    (5, 'Paris', '2022-05-01', '2022-05-10', 555),
    (6, 'London', '2022-06-01', '2022-06-10', 666),
    (7, 'Paris', '2022-07-01', '2022-07-10', 777),
    (8, 'Paris', '2022-08-01', '2022-08-10', 111),
    (9, 'Beijing', '2022-09-01', '2022-09-10', 111),
    (10, 'Paris', '2022-10-01', '2022-10-10', 555),
    (11, 'Paris', '2022-11-01', '2022-11-10', 555),
    (12, 'Paris', '2022-12-01', '2022-12-10', 555),
    (13, 'Paris', '2023-01-01', '2023-01-10', 555),
    (14, 'Paris', '2023-02-01', '2023-02-10', 555),
    (15, 'Paris', '2023-03-01', '2023-03-10', 555);

SELECT * FROM trips;

INSERT IGNORE INTO expenses (trip_id, item, date, amount)
VALUES
    (1, 'Airfare', '2022-01-01', 1000.00),
    (1, 'Hotel', '2022-01-01', 800.00),
    (2, 'Airfare', '2022-02-01', 1200.00),
    (2, 'Hotel', '2022-02-01', 900.00),
    (3, 'Airfare', '2022-03-01', 1100.00),
    (3, 'Hotel', '2022-03-01', 850.00),
    (4, 'Airfare', '2022-04-01', 950.00),
    (4, 'Hotel', '2022-04-01', 750.00),
    (5, 'Airfare', '2022-05-01', 1300.00),
    (5, 'Hotel', '2022-05-01', 1000.00),
    (6, 'Airfare', '2022-06-01', 1000.00),
    (6, 'Hotel', '2022-06-01', 800.00),
    (7, 'Airfare', '2022-07-01', 1200.00),
    (7, 'Hotel', '2022-07-01', 900.00);

SELECT * FROM expenses;

-- Querying the now created and filled tables

-- Query 1: List all names and job titles of employees. 
SELECT name, job_title
FROM emps; 

-- Query 2: List all names and zip codes of people who earn more than $50000 in salary. 
SELECT name, zip
FROM emps
WHERE salary > 50000; 

-- Query 3: List employee names and job titles of those who are currently traveling. You can use the function call NOW() to refer to today. And assume ReturnDate can be in the future. 
SELECT e.name, e.job_title
FROM emps e NATURAL JOIN trips t
WHERE t.departure_date < NOW() AND t.return_date > NOW()

-- Query 4: List the number of expense items and total amount of expenses for employee John Dough having traveled to Paris. 
SELECT Count(ee.item), Sum(ee.amount)
FROM emps e NATURAL JOIN trips t NATURAL JOIN expenses ee
WHERE e.name='John Dough' AND t.destination_city='Paris'; 


-- Query 5: List employee names who have traveled to Paris at least three times.
SELECT e.name
FROM emps e NATURAL JOIN trips t
WHERE t.destination_city='Paris'
GROUP BY t.social_security_no
HAVING Count(t.social_security_no) >= 3; -- HAVING has the same role as WHERE but we use it when we use GROUP BY