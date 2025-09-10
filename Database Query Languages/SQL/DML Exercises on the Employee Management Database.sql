-- Active: 1700211904021@@127.0.0.1@3306@dml_ex_employeemanagement

-- The following are exercises on the data manipulation language (DML) aspect of SQL. Select, Insert, Update, Delete.
-- The table creations are just so that we have a sample database to run the queries against.
-- Database Schema (given in slides): https://iili.io/JRCfwb4.png
-- Database Schema (MySql Workbench > Database > Reverse Engineer): https://iili.io/JRCIFAF.png

CREATE DATABASE DML_EX_EmployeeManagement;

SHOW DATABASES;

SELECT `SCHEMA_NAME` 
FROM `information_schema`.`SCHEMATA` 
WHERE `SCHEMA_NAME` NOT IN ('information_schema', 'mysql', 'performance_schema', 'sys'); -- This query retrieves only the user-created databases on the server not the default ones that come with it.

USE DML_EX_EmployeeManagement;

-- Creating the tables that make up the database
-- Keep in mind that the tables with attributes used as foreign keys in other tables should be at the top as the other tables should logically be referencing from something that already exists. This condition applies to table creation as well as table filling. So, simply respect this condition in the table creation phase then just fill the tables in the same order as the table creation.

CREATE TABLE IF NOT EXISTS regions (
    region_id INT PRIMARY KEY,
    region_name VARCHAR(50)
);

CREATE TABLE IF NOT EXISTS countries (
    country_id VARCHAR(2) PRIMARY KEY,
    country_name VARCHAR(50),
    region_id INT,
    FOREIGN KEY (region_id) REFERENCES regions(region_id)
);

CREATE TABLE IF NOT EXISTS locations (
    location_id INT PRIMARY KEY,
    street_address VARCHAR(255),
    postal_code VARCHAR(20),
    city VARCHAR(50),
    state_province VARCHAR(50),
    country_id VARCHAR(2),
    FOREIGN KEY (country_id) REFERENCES countries(country_id)
);

CREATE TABLE IF NOT EXISTS departments (
    department_id INT PRIMARY KEY,
    department_name VARCHAR(50),
    manager_id INT,
    location_id INT,
    FOREIGN KEY (location_id) REFERENCES locations(location_id)
);

CREATE TABLE IF NOT EXISTS jobs (
    job_id VARCHAR(10) PRIMARY KEY,
    job_title VARCHAR(50),
    min_salary DECIMAL(10,2),
    max_salary DECIMAL(10,2)
);

CREATE TABLE IF NOT EXISTS employees (
    employee_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    email VARCHAR(100),
    phone_number VARCHAR(20),
    hire_date DATE,
    job_id VARCHAR(10),
    salary DECIMAL(10,2),
    commission_percentage DECIMAL(5,2),
    manager_id INT,
    department_id INT,
    FOREIGN KEY (job_id) REFERENCES jobs(job_id),
    FOREIGN KEY (manager_id) REFERENCES employees(employee_id),
    FOREIGN KEY (department_id) REFERENCES departments(department_id)
);

CREATE TABLE IF NOT EXISTS job_grades (
    grade_level INT PRIMARY KEY,
    lowest_salary DECIMAL(10,2),
    highest_salary DECIMAL(10,2)
);

CREATE TABLE IF NOT EXISTS job_history (
    employee_id INT,
    start_date DATE,
    end_date DATE,
    job_id VARCHAR(10),
    department_id INT,
    PRIMARY KEY (employee_id, start_date),
    FOREIGN KEY (employee_id) REFERENCES employees(employee_id),
    FOREIGN KEY (job_id) REFERENCES jobs(job_id),
    FOREIGN KEY (department_id) REFERENCES departments(department_id)
);

SELECT COUNT(*) as table_count
FROM information_schema.tables
WHERE table_schema = DATABASE(); -- This query counts how many tables there are in the currently active database
-- It is a useful tool to verify whether we have successfully created all the desired tables

SHOW TABLES; -- To see all the table names / also another way of verification

-- Inserting some sample records into the tables

INSERT IGNORE INTO regions (region_id, region_name) VALUES
    (1, 'North America'),
    (2, 'Europe'),
    (3, 'Asia');

SELECT * FROM regions; -- Displays the table and all the data inside it - this is a mean of verifying that the insertion has successfully been executed

INSERT IGNORE INTO countries (country_id, country_name, region_id) VALUES
    ('US', 'United States', 1),
    ('CA', 'Canada', 1),
    ('UK', 'United Kingdom', 2),
    ('FR', 'France', 2),
    ('JP', 'Japan', 3),
    ('CN', 'China', 3);

SELECT * FROM countries;

INSERT IGNORE INTO locations (location_id, street_address, postal_code, city, state_province, country_id) VALUES
    (1, '123 Main St', '12345', 'Anytown', 'CA', 'US'),
    (2, '456 Oak St', '54321', 'Othercity', 'NY', 'US'),
    (3, '789 High St', '98765', 'London', NULL, 'UK'),
    (4, '101 Rue Street', '75001', 'Paris', NULL, 'FR'),
    (5, '1 Tokyo Street', '100-0001', 'Tokyo', NULL, 'JP'),
    (6, '2 Beijing Street', '100001', 'Beijing', NULL, 'CN');

SELECT * FROM locations;

INSERT IGNORE INTO departments (department_id, department_name, manager_id, location_id) VALUES
    (1, 'IT', NULL, 1),
    (2, 'Sales', 2, 2),
    (3, 'HR', 1, 3);

SELECT * FROM departments;

INSERT IGNORE INTO jobs (job_id, job_title, min_salary, max_salary) VALUES
    ('IT_PROG', 'Programmer', 50000.00, 100000.00),
    ('SA_MAN', 'Sales Manager', 75000.00, 150000.00),
    ('HR_REP', 'HR Representative', 60000.00, 120000.00),
    ('SH_CLERK', 'Shipping Clerk', 40000.00, 80000.00);

SELECT * FROM jobs;

INSERT IGNORE INTO employees (employee_id, first_name, last_name, email, phone_number, hire_date, job_id, salary, commission_percentage, manager_id, department_id) VALUES
    (1, 'John', 'Doe', 'john.doe@example.com', '123456789', '2022-01-01', 'IT_PROG', 80000.00, 0.05, 1, 1),
    (2, 'Jane', 'Smith', 'jane.smith@example.com', '987654321', '2022-02-01', 'SA_MAN', 100000.00, 0.10, 1, 2),
    (3, 'Bob', 'Johnson', 'bob.johnson@example.com', '555555555', '2022-03-01', 'HR_REP', 70000.00, 0.08, 1, 3),
    (4, 'Alice', 'Cooper', 'alice.cooper@example.com', '111111111', '2022-04-01', 'IT_PROG', 85000.00, 0.07, 1, 1),
    (5, 'Eva', 'Ford', 'eva.ford@example.com', '222222222', '2022-05-01', 'SA_MAN', 120000.00, 0.12, 2, 2),
    (6, 'David', 'Gibson', 'david.gibson@example.com', '333333333', '2022-06-01', 'HR_REP', 90000.00, 0.09, 1, 3),
    (7, 'John', 'Bull', 'john.bull@example.com', '444444444', '2022-07-01', 'IT_PROG', 80000.00, 0.05, NULL, 1),
    (8, 'Sam', 'Hill', 'sam.hill@example.com', '555555555', '2022-08-01', 'SH_CLERK', 45000.00, 0.03, 4, 3),
    (9, 'Emily', 'Reed', 'emily.reed@example.com', '666666666', '2022-09-01', 'SH_CLERK', 48000.00, 0.04, 5, 3);

SELECT * FROM employees;

INSERT IGNORE INTO job_grades (grade_level, lowest_salary, highest_salary) VALUES
    (1, 50000.00, 80000.00),
    (2, 80001.00, 120000.00),
    (3, 120001.00, 150000.00);

SELECT * FROM job_grades;

INSERT IGNORE INTO job_history (employee_id, start_date, end_date, job_id, department_id) VALUES
    (1, '2022-01-01', '2022-12-31', 'IT_PROG', 1),
    (2, '2022-02-01', '2022-12-31', 'SA_MAN', 2),
    (3, '2022-03-01', NULL, 'HR_REP', 3),
    (4, '2022-08-01', '2022-12-31', 'SH_CLERK', 3),
    (5, '2022-09-01', NULL, 'SH_CLERK', 3);

SELECT * FROM job_history;

-- Querying the now created and filled tables

-- Query 1: Find the name (first_name, last_name) and the salary of the employees who have a higher salary than the employee whose last_name='Bull'.
SELECT first_name, last_name, salary
FROM employees 
WHERE salary > (SELECT salary FROM employees WHERE last_name = 'Bull');

-- This is just to see what the sub-query alone returns
SELECT salary FROM employees WHERE last_name = 'Bull';

-- Query 2: Find the name (first_name, last_name) of all employees who work in the IT department.
SELECT first_name, last_name 
FROM employees 
WHERE department_id IN (SELECT department_id FROM departments WHERE department_name='IT');

-- This is just to see what the sub-query alone returns
SELECT department_id FROM departments WHERE department_name='IT';

-- Query 3: Find the name (first_name, last_name) of the employees who are managers.
SELECT first_name, last_name 
FROM employees 
WHERE (employee_id IN (SELECT manager_id FROM employees));
-- If we had just used employee_id IN manager_id then it would return the employees who are managers of themselves which is not realistic because nobody is their own manager - either you don't have a manager because you are the CEO or you are a manager who has a manager.

-- This is just to see what the sub-query alone returns
SELECT manager_id FROM employees;

-- Query 4: Find the name (first_name, last_name), and salary of the employees whose salary is greater than the average salary.
SELECT first_name, last_name, salary 
FROM employees 
WHERE salary > (SELECT AVG(salary) FROM employees);

-- This is just to see what the sub-query alone returns
SELECT AVG(salary) FROM employees;

-- Query 5: Find the name (first_name, last_name), and salary of the employees who earn the same salary as the minimum salary for all departments.
SELECT first_name, last_name, salary
FROM employees 
WHERE salary = (SELECT MIN(salary) FROM employees);

-- This is just to see what the sub-query alone returns
SELECT MIN(salary) FROM employees;

-- Query 6: Find the name (first_name, last_name) and salary of the employees who earn a salary that is higher than the salary of all the Shipping Clerk (JOB_ID = 'SH_CLERK'). Sort the results of the salary of the lowest to highest.
SELECT first_name,last_name, salary 
FROM employees 
WHERE salary > ALL (SELECT salary FROM employees WHERE job_id = 'SH_CLERK') 
ORDER BY salary ASC;

-- This is just to see what the sub-query alone returns
SELECT salary FROM employees WHERE job_id = 'SH_CLERK';

-- Query 7: Display the employee ID, first name, last name, salary, department_id of all employees whose salary is above average for their departments.
SELECT employee_id, first_name, last_name, salary, department_id
FROM employees AS A 
WHERE salary > (SELECT AVG(salary) FROM employees WHERE department_id = A.department_id);
-- Can't run this sub-query alone as it depends on a renaming that happens in the main query
-- the alias A is used for the employees table in the outer query. This alias is then referenced within the sub-query to ensure that the correlation refers to the outer query's context. The alias helps in disambiguating column references when you have nested or correlated queries. It ensures that the inner query is aware of the context of the outer query.

-- Query 8: Find the average salary of each department. (The query helps with understanding the results fetched in the previous query)
SELECT department_id, AVG(salary)
FROM employees
GROUP BY department_id;

-- Query 9: Get the details of all employees according to first name in descending order.
SELECT * 
FROM employees 
ORDER BY first_name DESC;

-- Query 10: Display the names (first_name, last_name) using alias name "First Name", "Last Name".
SELECT first_name "First Name", last_name "Last Name" 
FROM employees;

-- Query 11: Get the first three characters of first name of all employees.
SELECT SUBSTRING(first_name, 1, 3) 
FROM employees;

-- Query 12: Get unique department ID from employee table.
SELECT DISTINCT department_id 
FROM employees;

-- Query 13: Get the total salaries payable to employees.
SELECT SUM(salary) 
FROM employees;

-- Query 14: Get the maximum and minimum salary from employees table.
SELECT MAX(salary), MIN(salary) 
FROM employees;

-- Query 15: Get the average salary and number of employees in the employees table.
SELECT AVG(salary), COUNT(*) 
FROM employees;

-- Query 16: Get the number of designations available in the employees table.
SELECT COUNT(DISTINCT job_id) 
FROM employees;

-- Query 17: Display the names (first_name, last_name) and salary for all employees whose salary is not in the range $10,000 through $15,000.
SELECT first_name, last_name, salary 
FROM employees 
WHERE salary NOT BETWEEN 10000 AND 15000;

-- Query 18: Display the name (first_name, last_name) and department ID of all employees in departments 1 or 3 in ascending order.
SELECT first_name, last_name, department_id 
FROM employees 
WHERE department_id IN (1, 3) 
ORDER BY department_id ASC;

-- Query 19: Display first_name, last_name, and salary for all employees whose salary is not in the range $10,000 through $15,000 and are in department 1 or 3.
SELECT first_name, last_name, salary
FROM employees 
WHERE salary NOT BETWEEN 10000 AND 15000 
AND department_id IN (1, 3);

-- Query 20: Display the jobs/designations available in the employees table.
SELECT DISTINCT job_id 
FROM employees;

-- Query 21: Get the number of employees with the same job.
SELECT job_id, COUNT (*) 
FROM employees 
GROUP BY job_id; -- If you group by some column, it has to be in the select statement

-- Query 22: Get the department ID and the total salary payable in each department.
SELECT department_id, SUM(salary) 
FROM employees 
GROUP BY department_id;

-- Query 23: Get the maximum salary of an employee working as a Programmer.
SELECT MAX(salary) 
FROM employees 
WHERE job_id = 'IT_PROG';

-- Query 24: Display the name (first_name, last_name) and hire date for all employees who were hired in 1987.
SELECT first_name, last_name, hire_date 
FROM employees 
WHERE YEAR(hire_date) LIKE '1987%';

-- To avoid compromising the integrity of the sample database created to have something to run the queries against, there is also a drop database query at the end so that you can delete the entire database and start over and run all the table creation queries again to have them back in their original form.

-- Query 25: Change the email column of employees table with 'not available' for all employees.
UPDATE employees 
SET email='not available'; -- Not having a where statement means that we are going to execute this change for all rows of the table - so for all employees.

SELECT * FROM employees; -- This query is to view and verify that the change actually happened to the employees table.

-- Query 26: Change the salary of employee to 8000 whose ID is 8, if the existing salary is less than 5000.
UPDATE employees 
SET salary = 8000 
WHERE employee_id = 8 AND salary < 5000;

SELECT employee_id, salary
FROM employees
WHERE employee_id = 8; -- This query is to view and verify that the change actually happened to the employees table.

-- Query 27: Change job_id of employee whose ID is 5, to SH_CLERK if the employee belongs to department with ID 2 and the existing job ID does not start with SH.
UPDATE employees 
SET job_id = 'SH_CLERK' 
WHERE employee_id = 5
AND department_id = 2
AND NOT JOB_ID LIKE 'SH%';

SELECT employee_id, job_id
FROM employees
WHERE employee_id = 5; -- This query is to view and verify that the change actually happened to the employees table.

-- Query 28: Increase the minimum and maximum salary of HR_REP by 2000 as well as the salary for those employees by 20% and commission percent by .10.
UPDATE jobs, employees
SET jobs.min_salary = jobs.min_salary + 2000,
jobs.max_salary = jobs.max_salary + 2000,
employees.salary = employees.salary + (employees.salary * 0.20),
employees.commission_percentage = employees.commission_percentage + 0.10
WHERE jobs.job_id = 'HR_REP'
AND employees.job_id = 'HR_REP';

DROP DATABASE DML_EX_EmployeeManagement; -- Wipes the entire database with all its tables and their data off the MySQL server