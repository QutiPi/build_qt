#pragma once

#include <device.h>

#include "Drivers/I2C.h"


namespace QutiPi { namespace Hardware { namespace GPIO
{

    class MCP23008 : private Drivers::I2C
    {
        public:

            // Direction of pin
            enum class Direction
            {
                Input = 0,
                Output = 1,
            };

            // Port pull up mode
            enum class PullUp
            {
                Disable = 0,
                Enable = 1,

            };

            // Port state
            enum class State
            {
                Low = 0,
                High = 1,
            };


            // Available banks
            enum class Bank
            {
                A = 0,
            };


            // Available ports
            enum class Port
            {
                One = 0,
                Two = 1,
                Three = 2,
                Four = 3,
                Five = 4,
                Six = 5,
                Seven = 6,
                Eight = 7,
            };

            // Port polarity
            enum class Polarity
            {
                Same = 0,
                Inverted = 1,
            };

            // Interrupt configuration
            struct Interrupt
            {
                enum class Edge{
                    Rising = 1,
                    Falling = 0,
                };

                enum class Trigger{
                    Matches = 1,
                    Change = 0,
                };

                Edge edge;
                Trigger trigger;
            };

            // Class setup and destory
            MCP23008(Device ic);
            MCP23008(std::string location, char address, int timeout = 1000);
            ~MCP23008();

            // Standard device type
            using Drivers::I2C::Device;

            // Port controls
            void setDirection(Port port, Direction direction);
            void setPullUp(Port port, PullUp pullup);
            void setPolarity(Port port, Polarity polarity);
            void write(Port port, State state);
            int read(Port port);

            // Register block controls @todo needs implimenting
            // void setBankDirection(Port port, Direction direction);
            void setBankPullUp(Bank bank, PullUp pullup);
            void setBankPolarity(Bank bank, Polarity polarity);
            // void registerWrite(Port port, State state);
            // void registerRead(Port port);

            // Interrupt controls
            // void setMirroredInterrupt(); Only for MCP23017
            // void setInterrupt(Port port, Interrupt interrupt);


        protected:

        private:
            // Register addresses
            struct Addresses
            {
                char iodir_a = 0x00;
                char ipol_a = 0x01;
                char gpinten_a = 0x02;
                char defval_a = 0x03;
                char intcon_a = 0x04;
                char iocon_a = 0x05;
                char gppu_a = 0x06;
                char intf_a = 0x07;
                char intcap_a = 0x08;
                char gpio_a = 0x09;
                char olat_a = 0x0A;
            } m_addresses;

            // Configuration states
            struct Configurations
            {
                // Initial configuration (0x22)
                // 7: N/A
                // 6: N/A
                // 5: Sequential operation mode disabled
                // 4: Slew rate control for SDA disabled
                // 3: Hardware address disabled
                // 2: ODR INT active driver mode
                // 1: INT polarity active-high
                // 0: N/A
                char config_a = 0b00100010;

                // Hold set directions
                char direction_a;

                // Holds port values
                char port_a;

                // Hold pull up states
                char pullup_a;

                // Holds polarity configs
                char polarity_a;

                // Hold int config
                char int_a;
            } m_configurations;

            // Set init config
            void init();

            // Helper for writing and reading packages to selected register
            void writeRegisterBytes(char reg, char data);
            char readRegisterBytes(char reg);
    };

}}}
