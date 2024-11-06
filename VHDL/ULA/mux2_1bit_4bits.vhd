library IEEE;
use IEEE.std_logic_1164.all;

entity mux2_1bit_4bits is
    port ( 
        i_SEL : in std_logic;              -- Selector (1 bit)
        i_A   : in std_logic_vector(2 downto 0);  -- Data input A (3 bits)
        i_B   : in std_logic_vector(2 downto 0);  -- Data input B (3 bits)
        o_Q   : out std_logic_vector(2 downto 0)  -- Data output (3 bits)
    );
end mux2_1bit_4bits;

architecture Behavioral of mux2_1bit_4bits is
begin
    -- A operação bit a bit para a seleção da entrada com base no seletor
    o_Q(0) <= (i_A(0) and not i_SEL) or (i_B(0) and i_SEL);  -- Primeiro bit
    o_Q(1) <= (i_A(1) and not i_SEL) or (i_B(1) and i_SEL);  -- Segundo bit
    o_Q(2) <= (i_A(2) and not i_SEL) or (i_B(2) and i_SEL);  -- Terceiro bit
end Behavioral;
