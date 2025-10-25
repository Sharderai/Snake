#ifndef ICOMMAND_H
#define ICOMMAND_H

class ICommand
{
	public:
		virtual void execute() = 0;
		virtual ~ICommand() = default;
};

#endif 
