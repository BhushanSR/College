class PeepholeOptimizer:
    def __init__(self, optimization_techniques):
        self.optimization_techniques = optimization_techniques

    def optimize_intermediate_code(self, input_code):
        optimized_code = input_code
        for technique in self.optimization_techniques:
            optimized_code = technique.apply(optimized_code)
        return optimized_code


class IntermediateCode:
    def __init__(self, code):
        self.code = code

    def get_code(self):
        return self.code

    def set_code(self, new_code):
        self.code = new_code


class OptimizationTechnique:
    def __init__(self, name):
        self.name = name

    def apply(self, intermediate_code):
        # Implement your optimization technique here
        if self.name == "Remove Comments":
            optimized_code = intermediate_code.get_code().replace("#", "")
            return IntermediateCode(optimized_code)
        elif self.name == "Remove Redundant Whitespace":
            optimized_code = " ".join(intermediate_code.get_code().split())
            return IntermediateCode(optimized_code)
        elif self.name == "Remove Debugging Statements":
            optimized_code = intermediate_code.get_code().replace('print("The result is:", z)', "")
            return IntermediateCode(optimized_code)
        else:
            print("Unknown optimization technique")
            return intermediate_code


# Example usage
input_code = IntermediateCode("""
# This is some code with comments def foo():
x = 10
y = 20
z = x + y
print("The result is:", z)  # This is a debugging statement
""")


optimization_techniques = [
    OptimizationTechnique("Remove Comments"),
    OptimizationTechnique("Remove Redundant Whitespace"),
    OptimizationTechnique("Remove Debugging Statements")
]
peephole_optimizer = PeepholeOptimizer(optimization_techniques)
optimized_code = peephole_optimizer.optimize_intermediate_code(input_code)
print("Optimized Code:", optimized_code.get_code())
