from flask import Flask, request, jsonify
import subprocess
from flask_cors import CORS
import os

app = Flask(__name__)
CORS(app)  # This will enable CORS for all routes

@app.route('/', methods=['POST'])
def run_executable():
    try:
        body = request.get_json()

        input_code = body.get('code')

        executable_path = os.path.join(os.path.dirname(__file__), 'compiler')

        input_file_path = os.path.join(os.path.dirname(__file__), '..', 'code.txt')

        with open(input_file_path, 'w') as input_file:
            input_file.write(input_code)
        
        # Run the executable with the input file
        result = subprocess.run([executable_path, input_file_path], capture_output=True, text=True)


        # Check if the execution was successful
        if result.returncode == 0:
            output_dir = os.path.join(os.path.dirname(__file__), 'output')
            
            # Run the Makefile in the output directory
            make_result = subprocess.run(['make'], cwd=output_dir, capture_output=True, text=True)

            if make_result.returncode == 0:
                exec_result = subprocess.run(['./out'], cwd=output_dir, capture_output=True, text=True)

                return jsonify({
                    'status': 'success',
                    'compile': result.stdout,
                    'result' : exec_result.stdout
                })
            else:
                return jsonify({
                    'status': 'error',
                    'compile': result.stdout,
                    'result' : exec_result.stderr
                }), 500
        else:
            return jsonify({
                'status': 'error',
                'compile': result.stderr,
                'result' : 'No code'
            }), 500
    
    except Exception as e:
        print(e)
        return jsonify({
            'status': 'error',
            'message': str(e)
        }), 500

if __name__ == '__main__':
    app.run(debug=True)
