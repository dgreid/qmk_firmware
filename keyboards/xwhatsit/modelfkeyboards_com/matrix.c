/* Copyright 2020 Purdea Andrei
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

#define DAC_SCLK   B1
#define DAC_DIN    B2
#define DAC_SYNC_N B0

#define SHIFT_DIN  D4
#define SHIFT_OE   D5
#define SHIFT_STCP D6
#define SHIFT_SHCP D7

#define KEYBOARD_SETTLE_TIME_US 8
#define DAC_SETTLE_TIME_US 8

#define REPS 15

static inline uint8_t read_rows(void)
{
    uint8_t pc = PINC;
    uint8_t pd = PIND;
    return (pc >> 4) | (pd << 4);
}

void dac_init(void)
{
    setPinOutput(DAC_SCLK);
    setPinOutput(DAC_DIN);
    setPinOutput(DAC_SYNC_N);
    writePin(DAC_SYNC_N, 1);
    writePin(DAC_SCLK, 0);
    writePin(DAC_SCLK, 1);
    writePin(DAC_SCLK, 0);
}

void dac_write_threshold(uint16_t value)
{
    writePin(DAC_SYNC_N, 0);
    int i;
    for (i=0;i<16;i++)
    {
        writePin(DAC_DIN, (value >> 15) & 1);
        value <<= 1;
        writePin(DAC_SCLK, 1);
        writePin(DAC_SCLK, 0);
    }
    writePin(DAC_SYNC_N, 1);
    writePin(DAC_SCLK, 1);
    writePin(DAC_SCLK, 0);
    wait_us(DAC_SETTLE_TIME_US);
}

void shift_select_nothing(void)
{
    writePin(SHIFT_DIN, 0);
    int i;
    for (i=0;i<16;i++)
    {
        writePin(SHIFT_SHCP, 1);
        writePin(SHIFT_SHCP, 0);
    }
    writePin(SHIFT_STCP, 1);
    writePin(SHIFT_STCP, 0);
}

void shift_select_col(uint8_t col)
{
    int i;
    for (i=15; i>=0; i--)
    {
        writePin(SHIFT_DIN, !!(col == i));
        writePin(SHIFT_SHCP, 1);
        writePin(SHIFT_SHCP, 0);
    }
    writePin(SHIFT_STCP, 1);
    writePin(SHIFT_STCP, 0);
}

void shift_init(void)
{
    setPinOutput(SHIFT_DIN);
    setPinOutput(SHIFT_OE);
    setPinOutput(SHIFT_STCP);
    setPinOutput(SHIFT_SHCP);
    writePin(SHIFT_STCP, 0);
    writePin(SHIFT_SHCP, 0);
    shift_select_nothing();
    wait_us(KEYBOARD_SETTLE_TIME_US);
}


void test_col(uint8_t col, uint8_t *array)
{
    cli();
    shift_select_col(col);
    int i;
    for (i=0;i<16;i++)
    {
        uint8_t data = read_rows();
        array[i] = data;
    }
    sei();
    shift_select_nothing();
    wait_us(KEYBOARD_SETTLE_TIME_US);
}

void test_col_print_data(uint8_t col)
{
    uprintf("%d: ", col);
    uint8_t data[16];
    uint8_t sums[16 * 8];
    uint8_t i;
    for (i=0;i<16*8;i++)
    {
        sums[i] = 0;
    }
    for (i=0;i<REPS;i++)
    {
        test_col(col, data);
        uint8_t j;
        uint8_t ii = 0;
        for (j=0;j<16;j++)
        {
            uint8_t dataj = data[j];
            uint8_t k;
            for (k=0; k<8;k++)
            {
                ii += 1;
                sums[ii] += (dataj & 1);
                dataj >>= 1;
            }
        }
    }
    for (i=0;i<16*8;i++)
    {
        uprintf("%X", sums[i]);
    }
    print("\n");
}

void test_v1(void) {
    int i;
    for (i=7;i>0;i--) {
        uprintf("Starting test in %d\n", i);
        wait_ms(1000);
    }
    uprintf("shift_init()");
    shift_init();
    uprintf(" DONE\n");
    uprintf("dac_init()");
    dac_init();
    uprintf(" DONE\n");
    int d;
    for (d=0;d<1024;d++)
    {
        uprintf("Testing threshold: %d\n", d);
        dac_write_threshold(d);
        int c;
        for (c=0; c<10;c++)
        {
            test_col_print_data(c);
        }
        test_col_print_data(15);
    }
    uprintf("TEST DONE\n");
    while(1);
}

void matrix_init_custom(void) {
    test_v1();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool matrix_has_changed = false;
/*    current_matrix[0] ^= 1;
    uprintf("test %d\n", current_matrix[0]);
    bool matrix_has_changed = true;
*/
    // TODO: add matrix scanning routine here

    return matrix_has_changed;
}