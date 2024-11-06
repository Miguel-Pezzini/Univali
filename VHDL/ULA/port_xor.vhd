-- Simple OR gate design
library IEEE;
use IEEE.std_logic_1164.all;
use ieee.numeric_std.all; 

entity port_xor is
port(
  i_A: in std_logic_vector(2 downto 0);
  i_B: in std_logic_vector(2 downto 0);
  o_Q: out std_logic_vector(2 downto 0)
  );
end port_xor;

architecture arch of port_xor is
	begin
		 o_Q <= i_A xor i_B;
end arch;
