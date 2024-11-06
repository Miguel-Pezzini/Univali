-- Simple OR gate design
library IEEE;
use IEEE.std_logic_1164.all;
use ieee.numeric_std.all; 

entity port_or is
port(
  i_A: in std_logic_vector(2 downto 0);
  i_B: in std_logic_vector(2 downto 0);
  o_Q: out std_logic_vector(2 downto 0)
  );
end port_or;

architecture arch of port_or is
	begin
		 o_Q <= i_A or i_B;
end arch;
