# Sales Data Analyzer

This project is a command-line tool written in C for analyzing sales data. It provides features to import sales records, calculate key metrics, and generate detailed reports. The sales data is stored in a binary file for efficient storage and retrieval.

## Features

1. **Import Sales Data**: Add new sales records to the binary file.
2. **Calculate Metrics**: Compute total and average sales from the data.
3. **Generate Report**: Display a tabular report of all sales records.

## File Structure

- **sales_data.bin**: Binary file used to store sales records.
- **Source Code**: Contains the main program logic in C.


### Steps to Compile and Run

1. Clone the repository:
   ```bash
   git clone <TechieRS>
   cd <TechieRS>
   ```

2. Compile the code:
   ```bash
   gcc sales_data_analyzer.c -o sales_data_analyzer
   ```

3. Run the program:
   ```bash
   ./sales_data_analyzer
   ```
