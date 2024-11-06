-- Simple OR gate design
library IEEE;
use IEEE.std_logic_1164.all;

entity ULA is
port(
  i_A: in std_logic_vector(2 downto 0);
  i_B: in std_logic_vector(2 downto 0);
  i_E: in std_logic;
  i_CLK: in std_logic;
  i_SELECT: in std_logic_vector(2 downto 0);
  o_Q: out std_logic_vector(2 downto 0));
end ULA;

architecture arch of ULA is
  signal w_Soma, w_Sub, w_Increment, w_And, w_Or, w_Xor, w_Not, w_mux : std_logic_vector(2 downto 0);

  component somador
      port ( i_A: in std_logic_vector(2 downto 0);
             i_B: in std_logic_vector(2 downto 0);
             o_Q: out std_logic_vector(2 downto 0)
      );
  end component;
  
  component subtracao
      port ( i_A: in std_logic_vector(2 downto 0);
             i_B: in std_logic_vector(2 downto 0);
             o_Q: out std_logic_vector(2 downto 0)
      );
  end component;
  
  component incrementador
      port ( i_A: in std_logic_vector(2 downto 0);
             o_Q: out std_logic_vector(2 downto 0)
      );
  end component;
  
  component port_and
      port ( i_A: in std_logic_vector(2 downto 0);
             i_B: in std_logic_vector(2 downto 0);
             o_Q: out std_logic_vector(2 downto 0)
      );
  end component;
  
  component port_or
      port ( i_A: in std_logic_vector(2 downto 0);
             i_B: in std_logic_vector(2 downto 0);
             o_Q: out std_logic_vector(2 downto 0)
      );
  end component;
  
  component port_xor
      port ( i_A: in std_logic_vector(2 downto 0);
             i_B: in std_logic_vector(2 downto 0);
             o_Q: out std_logic_vector(2 downto 0)
      );
  end component;
  
  component port_not
      port ( i_A: in std_logic_vector(2 downto 0);
             o_Q: out std_logic_vector(2 downto 0)
      );
  end component;
  
    component mux8_3bits_4bits
      port ( i_SEL: in std_logic_vector(2 downto 0);
             i_Soma: in std_logic_vector(2 downto 0);
             i_Sub: in std_logic_vector(2 downto 0);
             i_Increment: in std_logic_vector(2 downto 0);
             i_a: in std_logic_vector(2 downto 0);
             i_And: in std_logic_vector(2 downto 0);
             i_Or: in std_logic_vector(2 downto 0);
             i_Xor: in std_logic_vector(2 downto 0);
             i_Not: in std_logic_vector(2 downto 0);
             o_Q: out std_logic_vector(2 downto 0)
      );
  end component;
  
  component registrador
      port ( i_E  : in std_logic;                       -- clear/reset
				 i_CLK    : in std_logic;  
             i_DATA : in std_logic_vector(2 downto 0);
             o_DATA  : out std_logic_vector(2 downto 0) 
      );
  end component;
  
  begin
    u_soma: somador
    port map ( i_A => i_A,
               i_B => i_B,
               o_Q => w_Soma
    );
    
    u_subtracao: subtracao
    port map ( i_A => i_A,
               i_B => i_B,
               o_Q => w_Sub
    );
    
    u_incrementador: incrementador
    port map ( i_A => i_A,
               o_Q => w_Increment
    );
    
    u_port_and: port_and
    port map ( i_A => i_A,
    		   i_B => i_B,
               o_Q => w_And
    );
    
    u_port_or: port_or
    port map ( i_A => i_A,
    		   i_B => i_B,
               o_Q => w_Or
    );
    
    u_port_xor: port_xor
    port map ( i_A => i_A,
    		      i_B => i_B,
               o_Q => w_Xor
    );
    
    u_port_not: port_not
    port map ( i_A => i_A,
               o_Q => w_Not
    );
    
    u_mux8_3bits_4bits: mux8_3bits_4bits
    port map ( i_SEL => i_SELECT,
    		      i_Soma => w_Soma,
               i_Sub => w_Sub,
               i_Increment => w_Increment,
               i_a => i_A,
               i_And => w_And, 
               i_Or => w_Or,
               i_Xor => w_Xor,
               i_Not => w_Not,
               o_Q => w_mux
    );
	 
	 u_registrador: registrador
	 port map ( i_E => i_E,
    		      i_CLK => i_CLK,
               i_DATA => w_mux,
               o_DATA => o_Q
    );
end arch;
