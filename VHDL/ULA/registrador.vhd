library ieee;
use ieee.std_logic_1164.all;

entity registrador is
    port (
        i_E  : in std_logic;                       -- clear/reset
        i_CLK    : in std_logic;  
        i_DATA : in std_logic_vector(2 downto 0);
        o_DATA  : out std_logic_vector(2 downto 0)   -- próximo estado
    );
end registrador;

architecture arch of registrador is
begin
    p_STATE_REGISTER: process(i_E, i_CLK)
    begin
        if (rising_edge(i_CLK) and i_E = '1') then
            o_DATA <= i_DATA;
        end if;
    end process;
  
end arch;