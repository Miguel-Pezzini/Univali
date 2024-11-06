-- Simple OR gate design
library IEEE;
use IEEE.std_logic_1164.all;
use ieee.numeric_std.all; 

entity somador is
port(
  i_A: in std_logic_vector(2 downto 0);
  i_B: in std_logic_vector(2 downto 0);
  o_Q: out std_logic_vector(2 downto 0)
  );
end somador;

architecture arch of somador is
	begin
		 o_Q <= std_logic_vector(unsigned(i_A) + unsigned(i_B));
end arch;
