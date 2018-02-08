export ENV=0

all: other_target target

other_target:
	@echo in other_target, ENV=$(ENV)

target: ENV=1
target: sub_target
	@echo in target, ENV=$(ENV)

sub_target:
	@echo in sub_target, ENV=$(ENV)
